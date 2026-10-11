#!/usr/bin/env bash
set -euo pipefail

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format is required; install it with your system package manager." >&2
  exit 127
fi

mode="${1:-}"
if [[ "$#" -gt 1 || ( -n "$mode" && "$mode" != "--check" ) ]]; then
  echo "Usage: $0 [--check]" >&2
  exit 2
fi

files=()
while IFS= read -r -d '' file; do
  [[ "$file" == */test/catch.hpp ]] && continue
  files+=("$file")
done < <(git ls-files -z -- '*.cpp' '*.h' '*.hpp')

if ((${#files[@]} == 0)); then
  echo "No tracked C++ files found." >&2
  exit 0
fi

if [[ "$mode" == "--check" ]]; then
  clang-format --dry-run --Werror "${files[@]}"
else
  clang-format -i "${files[@]}"
fi
