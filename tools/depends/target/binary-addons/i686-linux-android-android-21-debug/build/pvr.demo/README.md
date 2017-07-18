[![Build Status](https://travis-ci.org/kodi-pvr/pvr.demo.svg?branch=master)](https://travis-ci.org/kodi-pvr/pvr.demo)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/5120/badge.svg)](https://scan.coverity.com/projects/5120)

# Demo PVR
Demo PVR client addon for [Kodi] (http://kodi.tv)

## Build instructions

### Linux

1. `git clone https://github.com/xbmc/xbmc.git`
2. `git clone https://github.com/kodi-pvr/pvr.demo.git`
3. `cd pvr.demo && mkdir build && cd build`
4. `cmake -DADDONS_TO_BUILD=pvr.demo -DADDON_SRC_PREFIX=../.. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=../../xbmc/addons -DPACKAGE_ZIP=1 ../../xbmc/cmake/addons`
5. `make`

##### Useful links

* [Kodi's PVR user support] (http://forum.kodi.tv/forumdisplay.php?fid=167)
* [Kodi's PVR development support] (http://forum.kodi.tv/forumdisplay.php?fid=136)
