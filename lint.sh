#!/usr/bin/env bash
find ./ -type f \( -iname \*.cpp -o -iname \*.h \) | grep -v "[test|build]" | xargs cpplint --filter=-legal/copyright
