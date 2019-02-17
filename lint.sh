#!/usr/bin/env bash
sudo apt-get install libffi-dev libssl-dev
pip install requests[security]
pip install cpplint
find ./ -type f \( -iname \*.cpp -o -iname \*.h \) | grep -v "test" | grep -v "Compiler" |  xargs cpplint --filter=-legal/copyright,-build/include_subdir
