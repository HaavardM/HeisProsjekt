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
    

COPY ./install_dependencies.sh /
WORKDIR /
RUN /bin/bash install_dependencies.sh
RUN rm install_dependencies.sh
RUN ldconfig -v | grep -v ^$'\t'.


