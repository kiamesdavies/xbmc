file(COPY /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/sidplay2/src/sidplay2)
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/01-m4-tests.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/02-inherited.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/03-operator.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/04-includes.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/05-enable-pic.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/06-include-macros.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audiodecoder.sidplay/depends/common/sidplay2/07-replace-linux-header.patch")
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/sidplay2/src/sidplay2")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/sidplay2/src/sidplay2)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/sidplay2/src/sidplay2")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/sidplay2/src/sidplay2)
