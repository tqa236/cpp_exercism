#!/usr/bin/env bash
apt-get install libffi-dev libssl-dev
pip install requests[security]
pip install cpplint
find . -iname "*.cpp" | grep -v "test" | grep -v "Compiler" |  xargs cpplint --filter=-legal/copyright,-build/include_subdir
