#!/usr/bin/env bash
set -uo pipefail

compiler="${CXX:-g++}"
jobs="${CI_TEST_JOBS:-$(nproc)}"
if ! [[ "$jobs" =~ ^[1-9][0-9]*$ ]]; then
  echo "CI_TEST_JOBS must be a positive integer; got '$jobs'." >&2
  exit 2
fi

if ! command -v "$compiler" >/dev/null 2>&1; then
  echo "C++ compiler '$compiler' was not found." >&2
  exit 127
fi

cxx_flags="-DCATCH_CONFIG_NO_POSIX_SIGNALS"
if [[ "$compiler" == *clang++* ]] &&
  printf '' | "$compiler" -Werror -Wc2y-extensions -x c++ -fsyntax-only \
    - >/dev/null 2>&1; then
  cxx_flags+=" -Wno-error=c2y-extensions"
fi

temp_root="$(mktemp -d "${RUNNER_TEMP:-${TMPDIR:-/tmp}}/cpp-exercism-tests.XXXXXX")"
build_root="$temp_root/build"
log_root="$temp_root/logs"
result_root="$temp_root/results"
mkdir -p "$log_root" "$result_root"
trap 'rm -rf "$temp_root"' EXIT

exercises=()
for cmake_file in */CMakeLists.txt; do
  [[ -f "$cmake_file" ]] || continue
  exercises+=("${cmake_file%/CMakeLists.txt}")
done

if ((${#exercises[@]} == 0)); then
  echo "No CMake exercise projects found." >&2
  exit 1
fi

export CI_BUILD_ROOT="$build_root"
export CI_LOG_ROOT="$log_root"
export CI_RESULT_ROOT="$result_root"
export CI_CXX="$compiler"
export CI_CXX_FLAGS="$cxx_flags"

printf '%s\0' "${exercises[@]}" |
  xargs -0 -r -P "$jobs" -n 1 bash -c '
    exercise="$1"
    name="${exercise##*/}"
    build_dir="$CI_BUILD_ROOT/$name"
    log_file="$CI_LOG_ROOT/$name.log"

    if (
      set -euo pipefail
      cmake -S "$exercise" -B "$build_dir" \
        -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
        -DCMAKE_CXX_COMPILER="$CI_CXX" \
        -DCMAKE_CXX_FLAGS="$CI_CXX_FLAGS" \
        -DEXERCISM_RUN_ALL_TESTS=ON
      cmake --build "$build_dir" --parallel 1 --target "$name"
      "$build_dir/$name"
    ) >"$log_file" 2>&1; then
      printf "0\n" > "$CI_RESULT_ROOT/$name"
    else
      status=$?
      printf "%s\n" "$status" > "$CI_RESULT_ROOT/$name"
    fi
  ' _
xargs_status=$?

passed=0
failed=0
for exercise in "${exercises[@]}"; do
  name="${exercise##*/}"
  result_file="$result_root/$name"
  if [[ ! -f "$result_file" ]]; then
    printf 'FAIL  %s (worker did not report a result)\n' "$exercise"
    ((failed += 1))
    continue
  fi

  status="$(<"$result_file")"
  if [[ "$status" == "0" ]]; then
    ((passed += 1))
  else
    printf 'FAIL  %s (exit %s)\n' "$exercise" "$status"
    ((failed += 1))
  fi
done

printf '\nTest summary: %d passed, %d failed, %d total (up to %d in parallel).\n' \
  "$passed" "$failed" "${#exercises[@]}" "$jobs"

if ((failed > 0)); then
  for exercise in "${exercises[@]}"; do
    name="${exercise##*/}"
    result_file="$result_root/$name"
    [[ -f "$result_file" && "$(<"$result_file")" != "0" ]] || continue
    echo "::group::Failure details: $exercise"
    cat "$log_root/$name.log"
    echo "::endgroup::"
  done
fi

if ((xargs_status != 0)); then
  echo "One or more test workers could not be started (xargs exit $xargs_status)." >&2
  exit "$xargs_status"
fi
((failed == 0))
