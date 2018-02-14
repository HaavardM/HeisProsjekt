#!/bin/bash

git clone https://github.com/Linux-Comedi/comedilib.git
cd comedilib
./autogen.sh
./configure --with-udev-hotplug=/lib --sysconfdir=/etc
make
make install
cd ..
rm -rf comedilib
