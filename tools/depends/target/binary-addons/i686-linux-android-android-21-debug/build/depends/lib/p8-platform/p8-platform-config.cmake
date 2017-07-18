# - p8-platform config mode
#
# Defines the following variables:
#  p8-platform_FOUND        - true
#  p8-platform_VERSION      - version of the platform library found, e.g. 0.2
#  p8-platform_INCLUDE_DIRS - header directories with which to compile
#  p8-platform_LINKER_FLAGS - flags that must be passed to the linker
#  p8-platform_LIBRARIES    - names of the libraries with which to link
#  p8-platform_LIBRARY_DIRS - directories in which the libraries are situated
#
# propagate these properties from one build system to the other
set (p8-platform_VERSION "2.1")
set (p8-platform_INCLUDE_DIRS /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/include/p8-platform /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/include)
set (p8-platform_LIBRARY_DIRS "")
set (p8-platform_LINKER_FLAGS "")
set (p8-platform_CONFIG_VARS "")

# libraries come from the build tree where this file was generated
if(WIN32)
  set (p8-platform_LIBRARY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/lib/p8-platform.lib")
else(WIN32)
  set (p8-platform_LIBRARY "-L/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/lib -lp8-platform")
endif(WIN32)
set (p8-platform_LIBRARIES ${p8-platform_LIBRARY} "")
mark_as_advanced (p8-platform_LIBRARY)

# add the library as a target, so that other things in the project including
# this file may depend on it and get rebuild if this library changes.
add_library (p8-platform UNKNOWN IMPORTED)
set_property (TARGET p8-platform PROPERTY IMPORTED_LOCATION "${p8-platform_LIBRARY}")
