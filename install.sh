#!/usr/bin/env bash
# This file is only use for Travis CI
sudo apt-get install gcc
sudo add-apt-repository -y ppa:samuel-bachmann/boost
sudo apt-get -qq -d update
sudo apt-get install boost1.60
