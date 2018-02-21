FROM haavardm/ttk4245:1.0
MAINTAINER Håvard Skåra Mellbye

COPY ./ /HeisProsjekt
WORKDIR /HeisProsjekt
RUN /bin/bash ./build_test.sh
