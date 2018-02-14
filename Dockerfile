FROM ubuntu:16.04
MAINTAINER Håvard Skåra Mellbye

RUN apt-get update -qq && apt-get install -yqq \ 
    build-essential \
    cmake \ 
    git \
    autoconf \
    libtool \ 
    swig \
    python \
    flex \
    byacc \
    bison
    

RUN mkdir -p /opt/elevator_project
COPY ./ /opt/elevator_project/HeisProsjekt
WORKDIR /opt/elevator_project/HeisProsjekt
RUN /bin/bash install_dependencies.sh
RUN /bin/bash build_test.sh

