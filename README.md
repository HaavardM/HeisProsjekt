# HeisProsjekt
Heisprosjekt i C

[![Build Status](https://travis-ci.org/HaavardM/HeisProsjekt.svg)](https://travis-ci.org/HaavardM/HeisProsjekt)

## How to build:

Install docker and run:
```
docker build .
```
to build and test code

## How to build parent image
```
docker build . -f docker/system/Dockerfile -t YOUR_TAG_HERE
docker push YOUR_TAG_HERE
```

