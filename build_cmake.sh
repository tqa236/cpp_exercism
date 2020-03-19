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
      cd build || exit
      cmake -DBoost_USE_STATIC_LIBS=ON -G "Unix Makefiles" ..
      cd ../.. || exit
    else
      cd ..
    fi
done
