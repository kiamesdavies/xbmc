if("32190045c7eb6883c0662db2f91b4ceeab904fc2" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

set(run 0)

if("/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitinfo.txt" IS_NEWER_THAN "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitclone-lastrun.txt")
  set(run 1)
endif()

if(NOT run)
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform'")
endif()

set(git_options)

# disable cert checking if explicitly told not to do it
set(tls_verify "")
if(NOT "x" STREQUAL "x" AND NOT tls_verify)
  list(APPEND git_options
    -c http.sslVerify=false)
endif()

set(git_clone_options)

set(git_shallow "1")
if(git_shallow)
  list(APPEND git_clone_options --depth 1 --no-single-branch)
endif()

# try the clone 3 times incase there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" ${git_options} clone ${git_clone_options} --origin "origin" "https://github.com/xbmc/platform.git" "p8-platform"
    WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/xbmc/platform.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} checkout 32190045c7eb6883c0662db2f91b4ceeab904fc2
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '32190045c7eb6883c0662db2f91b4ceeab904fc2'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} submodule init 
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} submodule update --recursive --init 
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitinfo.txt"
    "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitclone-lastrun.txt"
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/p8-platform/src/p8-platform-stamp/p8-platform-gitclone-lastrun.txt'")
endif()

