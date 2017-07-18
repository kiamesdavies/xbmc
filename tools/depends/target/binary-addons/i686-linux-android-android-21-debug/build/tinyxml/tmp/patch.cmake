file(COPY /root/kodi-android/cmake/addons/depends/common/tinyxml/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/tinyxml/src/tinyxml)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/tinyxml/src/tinyxml")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/tinyxml/src/tinyxml)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/tinyxml/src/tinyxml")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/tinyxml/src/tinyxml)
