#!/bin/bash

git clone https://github.com/Linux-Comedi/comedilib.git
cd comedilib
./autogen.sh
./configure --with-udev-hotplug=/lib --sysconfdir=/etc
make
sudo make install