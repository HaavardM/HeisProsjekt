#!/bin/bash
cd "${0%/*}"
mkdir build
cd build
cmake ..
make
set -e
./heisprosjekt_test
