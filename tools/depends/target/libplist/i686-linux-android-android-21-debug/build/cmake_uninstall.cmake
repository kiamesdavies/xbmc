IF(NOT EXISTS "/root/kodi-android/tools/depends/target/libplist/i686-linux-android-android-21-debug/build/install_manifest.txt")
	MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/root/kodi-android/tools/depends/target/libplist/i686-linux-android-android-21-debug/build/install_manifest.txt\"")
ENDIF(NOT EXISTS "/root/kodi-android/tools/depends/target/libplist/i686-linux-android-android-21-debug/build/install_manifest.txt")

FILE(READ "/root/kodi-android/tools/depends/target/libplist/i686-linux-android-android-21-debug/build/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
	MESSAGE(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
	IF(EXISTS "$ENV{DESTDIR}${file}")
		EXEC_PROGRAM(
			"/opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
			OUTPUT_VARIABLE rm_out
			RETURN_VALUE rm_retval
		)
		IF(NOT "${rm_retval}" STREQUAL 0)
			MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
		ENDIF(NOT "${rm_retval}" STREQUAL 0)
	ELSE(EXISTS "$ENV{DESTDIR}${file}")
		MESSAGE(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
	ENDIF(EXISTS "$ENV{DESTDIR}${file}")
ENDFOREACH(file)
