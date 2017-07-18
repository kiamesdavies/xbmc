file(COPY /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.flac/depends/common/flac/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/flac/src/flac)
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.flac/depends/common/flac/01-nasm.patch")
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/flac/src/flac")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/flac/src/flac)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/flac/src/flac")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/flac/src/flac)
