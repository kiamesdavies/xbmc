if("36fb49371dbce49bf470a5bb1fc51b74b4a3612d" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

set(run 0)

if("/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitinfo.txt" IS_NEWER_THAN "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitclone-lastrun.txt")
  set(run 1)
endif()

if(NOT run)
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform'")
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
    COMMAND "/usr/bin/git" ${git_options} clone ${git_clone_options} --origin "origin" "https://github.com/xbmc/kodi-platform" "kodi-platform"
    WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/xbmc/kodi-platform'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} checkout 36fb49371dbce49bf470a5bb1fc51b74b4a3612d
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '36fb49371dbce49bf470a5bb1fc51b74b4a3612d'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} submodule init 
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform'")
endif()

execute_process(
  COMMAND "/usr/bin/git" ${git_options} submodule update --recursive --init 
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitinfo.txt"
    "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitclone-lastrun.txt"
  WORKING_DIRECTORY "/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/root/kodi-android/tools/depends/target/binary-addons/i686-linux-android-android-21-debug/build/kodi-platform/src/kodi-platform-stamp/kodi-platform-gitclone-lastrun.txt'")
endif()

