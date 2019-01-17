#!/usr/bin/env bash
# Automatically build all neccessary files for an exercise
cd $1
echo $1
file_name=${1/-/_}
echo $file_name
touch $file_name.h $file_name.cpp
echo $file_name
mkdir build
cd build
cmake -G "Unix Makefiles" ..
