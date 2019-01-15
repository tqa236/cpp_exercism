# Automatically build all neccessary files for an exercise
cd $1
touch $1.h $1.cpp
mkdir build
cd build
cmake -G "Unix Makefiles" ..
