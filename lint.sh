#!/usr/bin/env bash
find . -iname "*.cpp" | grep -v "test" | grep -v "Compiler" |  xargs cpplint --filter=-legal/copyright,-build/include_subdir
