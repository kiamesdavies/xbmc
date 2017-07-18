file(COPY /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/pvr.hdhomerun/depends/common/hdhomerun/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/hdhomerun/src/hdhomerun)
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/pvr.hdhomerun/depends/common/hdhomerun/1.patch")
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/hdhomerun/src/hdhomerun")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/hdhomerun/src/hdhomerun)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/hdhomerun/src/hdhomerun")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/hdhomerun/src/hdhomerun)
