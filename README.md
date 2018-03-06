# HeisProsjekt
Heisprosjekt i C

[![Build Status](https://travis-ci.org/HaavardM/HeisProsjekt.svg)](https://travis-ci.org/HaavardM/HeisProsjekt)

## How to build:

### Using docker: 
Install docker and run:
```
docker build .
```
to build and test code

### Using CMake and make
Install CMake:
```
sudo apt-get install cmake
```
Create build directory and change directory
```
mkdir build
cd build
```
Run CMake with parent directory
```
cmake ..
```
Run make on generated makefile
```
make
```

Run executable
```
./heisprosjekt
```

### Using build script
In project folder, run either build.sh or build_test.sh
```
./build.sh
```
If the scripts won't start, make it an executable
```
chmod +x build.sh
```
Run the built binary
```
./heisprosjekt
```




## How to build parent image
```
docker build . -f docker/system/Dockerfile -t YOUR_TAG_HERE
docker push YOUR_TAG_HERE
```

