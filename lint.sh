#!/usr/bin/env bash
pip install cpplint
find . -iname "*.cpp" | grep -v "test" | grep -v "Compiler" |  xargs cpplint --filter=-legal/copyright,-build/include_subdir
