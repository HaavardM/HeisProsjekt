#!/bin/bash
mkdir build
cd build
cmake ..
make
set -e
./heisprosjekt_test
