#!/usr/bin/env bash
# Automatically build all neccessary files for an exercise
for path in */; do
    [ -d "${path}" ] || continue # if not a directory, skip
    dirname="$(basename "${path}")"
    cd "$dirname" || exit
    if ! [ -d "./build" ]; then
      cat "../code_coverage_CMake.txt" >> "CMakeLists.txt"
      file_name=${path::-1}
      file_name=${file_name//-/_}
      echo "$file_name"
      touch "$file_name.h" "$file_name.cpp"
      echo "$file_name"
      mkdir build
    fi
    cd build || exit
    cmake -DEXERCISM_RUN_ALL_TESTS=1 -G "Unix Makefiles" ..
    cd ../.. || exit
done
