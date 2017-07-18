file(COPY /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/CMakeLists.txt
                     DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/lame/src/lame)
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/01-field-width-fix.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/02-unbreak-ftbfs-gcc4.4.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/03-privacy-breach.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/04-msse.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/05-ansi2knr2devnull.patch")
execute_process(COMMAND /usr/bin/patch -p1 -i "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/audioencoder.lame/depends/common/lame/06-gtk1-ac-directives.patch")
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/lame/src/lame")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.sub DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/lame/src/lame)
message(STATUS "AUTOCONF: copying /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess to /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/lame/src/lame")

                 file(COPY /opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/automake-1.15/config.guess DESTINATION /root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/lame/src/lame)
