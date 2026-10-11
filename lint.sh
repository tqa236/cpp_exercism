#!/usr/bin/env bash
set -euo pipefail

if ! command -v cpplint >/dev/null 2>&1; then
  echo "cpplint is required; install it with 'python -m pip install cpplint'." >&2
  exit 127
fi

find . -type f \( -iname '*.cpp' -o -iname '*.h' \) \
  ! -path '*test*' \
  ! -path '*Compiler*' \
  -print0 |
  xargs -0 -r cpplint \
    --filter=-legal/copyright,-build/include_subdir,-build/header_guard,\
-build/include,-build/include_what_you_use,-build/namespaces,\
-build/storage_class,-readability/braces,-readability/casting,\
-readability/todo,-runtime/explicit,-runtime/init,-runtime/int,\
-whitespace/braces,-whitespace/ending_newline,-whitespace/indent_namespace,\
-whitespace/semicolon
