# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_IFW "")
SET(CPACK_BINARY_NSIS "")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_RPM "")
SET(CPACK_BINARY_STGZ "")
SET(CPACK_BINARY_TBZ2 "")
SET(CPACK_BINARY_TGZ "")
SET(CPACK_BINARY_TXZ "")
SET(CPACK_BINARY_TZ "")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_GENERATOR "ZIP")
SET(CPACK_INSTALL_CMAKE_PROJECTS "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/pvr.stalker-prefix/src/pvr.stalker-build;pvr.stalker;ALL;/")
SET(CPACK_INSTALL_PREFIX "/opt/android-dev/android/xbmc-depends/i686-linux-android-android-21-debug")
SET(CPACK_MODULE_PATH "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/pvr.stalker;/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/lib/kodi;/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/depends/share/kodi/cmake")
SET(CPACK_NSIS_DISPLAY_NAME "pvr.stalker 0.1.1")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_PACKAGE_NAME "pvr.stalker 0.1.1")
SET(CPACK_OUTPUT_CONFIG_FILE "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/pvr.stalker-prefix/src/pvr.stalker-build/CPackConfig.cmake")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/cmake-3.6/Templates/CPack.GenericDescription.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "pvr.stalker built using CMake")
SET(CPACK_PACKAGE_FILE_NAME "pvr.stalker-0.1.1-Android")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "pvr.stalker 0.1.1")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "pvr.stalker 0.1.1")
SET(CPACK_PACKAGE_NAME "pvr.stalker")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "Humanity")
SET(CPACK_PACKAGE_VERSION "0.1.1")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "1")
SET(CPACK_RESOURCE_FILE_LICENSE "/opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/cmake-3.6/Templates/CPack.GenericLicense.txt")
SET(CPACK_RESOURCE_FILE_README "/opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/cmake-3.6/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/opt/android-dev/android/xbmc-depends/x86_64-linux-gnu-native/share/cmake-3.6/Templates/CPack.GenericWelcome.txt")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/pvr.stalker-prefix/src/pvr.stalker-build/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_TBZ2 "ON")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TXZ "ON")
SET(CPACK_SOURCE_TZ "ON")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_SYSTEM_NAME "Android")
SET(CPACK_TOPLEVEL_TAG "Android")
SET(CPACK_WIX_SIZEOF_VOID_P "4")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/pvr.stalker-prefix/src/pvr.stalker-build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
