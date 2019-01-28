#!/usr/bin/env bash
# Automatically build all neccessary files for an exercise
for path in */; do
    [ -d "${path}" ] || continue # if not a directory, skip
    dirname="$(basename "${path}")"
    cd $dirname
    if ! [ -d "./build" ]; then
      file_name=${path::-1}
      file_name=${file_name//-/_}
      echo $file_name
      touch $file_name.h $file_name.cpp
      echo $file_name
      mkdir build
      cd build
      cmake -G "Unix Makefiles" ..
      cd ../..
    else
      cd ..
    fi
done
