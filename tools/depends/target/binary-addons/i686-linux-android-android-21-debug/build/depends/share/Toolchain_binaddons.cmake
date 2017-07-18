set(OS "android")
set(CPU "i686")
set(PLATFORM "")

set(CMAKE_FIND_ROOT_PATH /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends)

# set CORE_SYSTEM_NAME and CMAKE_SYSTEM_NAME (sets CMAKE_CROSSCOMPILING)
if(OS STREQUAL linux)
  set(CMAKE_SYSTEM_NAME Linux)
  set(CORE_SYSTEM_NAME linux)
  if(PLATFORM STREQUAL raspberry-pi)
    set(CORE_SYSTEM_NAME rbpi)
  endif()
elseif(OS STREQUAL android)
  set(CMAKE_SYSTEM_NAME Android)
  set(CORE_SYSTEM_NAME android)
elseif(OS STREQUAL osx)
  set(CMAKE_SYSTEM_NAME Darwin)
  set(CORE_SYSTEM_NAME osx)
elseif(OS STREQUAL ios)
  set(CMAKE_SYSTEM_NAME Darwin)
  set(CORE_SYSTEM_NAME ios)
endif()

if(CORE_SYSTEM_NAME STREQUAL ios OR CORE_SYSTEM_NAME STREQUAL osx)
  set(CMAKE_OSX_SYSROOT /opt/android-sdk-linux)
  list(APPEND CMAKE_FIND_ROOT_PATH ${CMAKE_OSX_SYSROOT} ${CMAKE_OSX_SYSROOT}/usr /usr/X11R6)
  set(CMAKE_LIBRARY_PATH /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/lib:/opt/android-sdk-linux/lib:/usr/X11R6/lib)
  set(CMAKE_INCLUDE_PATH /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/include:/opt/android-sdk-linux/include:/usr/X11R6/include)
endif()
set(CMAKE_SYSTEM_VERSION 1)

# specify the cross compiler
set(CMAKE_C_COMPILER /opt/android-toolchain-x86/android-21/bin/i686-linux-android-gcc)
set(CMAKE_CXX_COMPILER /opt/android-toolchain-x86/android-21/bin/i686-linux-android-g++)
set(CMAKE_AR /opt/android-toolchain-x86/android-21/bin/i686-linux-android-ar CACHE FILEPATH "Archiver")
set(CMAKE_LINKER /opt/android-toolchain-x86/android-21/bin/i686-linux-android-ld CACHE FILEPATH "Linker")
set(CMAKE_OBJDUMP /opt/android-toolchain-x86/android-21/bin/i686-linux-android-objdump CACHE FILEPATH "Objdump")
set(CMAKE_RANLIB /opt/android-toolchain-x86/android-21/bin/i686-linux-android-ranlib CACHE FILEPATH "Ranlib")

if(no STREQUAL "yes")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "")
endif()

# where is the target environment
if(NOT "/opt/android-toolchain-x86/android-21" STREQUAL "")
  list(APPEND CMAKE_FIND_ROOT_PATH /opt/android-toolchain-x86/android-21/sysroot/usr)
endif()

# add RBPI's firmware directories
if(CORE_SYSTEM_NAME STREQUAL rbpi)
  list(APPEND CMAKE_FIND_ROOT_PATH /opt/vc)
  list(APPEND CMAKE_LIBRARY_PATH /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/lib:/opt/vc/lib)
  list(APPEND CMAKE_INCLUDE_PATH /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/include:/opt/vc/include)
endif()

# add Android directories and tools
if(CORE_SYSTEM_NAME STREQUAL android)
  set(NDKROOT /opt/android-ndk-r12b)
  set(SDKROOT /opt/android-sdk-linux)
  set(SDK_PLATFORM android-21)
  string(REPLACE ":" ";" SDK_BUILDTOOLS_PATH "/opt/android-sdk-linux/tools:/opt/android-sdk-linux/platform-tools:/opt/android-sdk-linux/build-tools/20.0.0")
endif()

set(CMAKE_C_FLAGS "-DANDROID -fexceptions -fPIC -DPIC -Og -g -D_DEBUG  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_CXX_FLAGS "-std=gnu++11 -DANDROID -fexceptions -fPIC -DPIC -frtti -Og -g -D_DEBUG  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_C_FLAGS_RELEASE "-DANDROID -fexceptions -fPIC -DPIC  -Os  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_CXX_FLAGS_RELEASE "-std=gnu++11 -DANDROID -fexceptions -fPIC -DPIC -frtti  -Os  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_C_FLAGS_DEBUG "-DANDROID -fexceptions -fPIC -DPIC -Og -g -D_DEBUG  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_CXX_FLAGS_DEBUG "-std=gnu++11 -DANDROID -fexceptions -fPIC -DPIC -frtti -Og -g -D_DEBUG  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_CPP_FLAGS "-DANDROID -fexceptions -fPIC -DPIC -Og -g -D_DEBUG  -I/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/include/android-21")
set(CMAKE_LD_FLAGS "-L/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug/lib/android-21  ")
set(ENV{CFLAGS} ${CMAKE_C_FLAGS})
set(ENV{CXXFLAGS} ${CMAKE_CXX_FLAGS})
set(ENV{CPPFLAGS} ${CMAKE_CPP_FLAGS})
set(ENV{LDFLAGS} ${CMAKE_LD_FLAGS})
# search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Binary Addons
if(NOT CORE_SYSTEM_NAME STREQUAL linux)
  set(ADDONS_PREFER_STATIC_LIBS ON)
endif()

set(KODI_DEPENDSBUILD 1)
