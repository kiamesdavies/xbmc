file(COPY /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/pvr.stalker/depends/common/libxml2/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/libxml2/src/libxml2)
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/pvr.stalker/depends/common/libxml2/win32_io.patch")
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/libxml2/src/libxml2")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/libxml2/src/libxml2)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/libxml2/src/libxml2")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/libxml2/src/libxml2)
