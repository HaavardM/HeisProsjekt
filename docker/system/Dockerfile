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
    

COPY ./ /HeisProsjekt
WORKDIR /HeisProsjekt
RUN /bin/bash install_dependencies.sh
WORKDIR /
RUN rm -rf /HeisProsjekt

