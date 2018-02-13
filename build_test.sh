#!/bin/bash
mkdir build
cd build
set -e
cmake ..
make
./heisprosjekt_test
