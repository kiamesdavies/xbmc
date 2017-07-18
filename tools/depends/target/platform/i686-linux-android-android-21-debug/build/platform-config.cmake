# - platform config mode
#
# Defines the following variables:
#  platform_FOUND        - true
#  platform_VERSION      - version of the platform library found, e.g. 0.2
#  platform_INCLUDE_DIRS - header directories with which to compile
#  platform_LINKER_FLAGS - flags that must be passed to the linker
#  platform_LIBRARIES    - names of the libraries with which to link
#  platform_LIBRARY_DIRS - directories in which the libraries are situated
#
# propagate these properties from one build system to the other
set (platform_VERSION "1.0")
set (platform_INCLUDE_DIRS /opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/platform /opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include)
set (platform_LIBRARY_DIRS "")
set (platform_LINKER_FLAGS "")
set (platform_CONFIG_VARS "")

# libraries come from the build tree where this file was generated
if(WIN32)
  set (platform_LIBRARY "/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug//opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/lib/platform.lib")
else(WIN32)
  set (platform_LIBRARY "-L/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug//opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/lib -lplatform")
endif(WIN32)
set (platform_LIBRARIES ${platform_LIBRARY} "")
mark_as_advanced (platform_LIBRARY)

# add the library as a target, so that other things in the project including
# this file may depend on it and get rebuild if this library changes.
add_library (platform UNKNOWN IMPORTED)
set_property (TARGET platform PROPERTY IMPORTED_LOCATION "${platform_LIBRARY}")
