[[ -f $(dirname $0)/buildhelpers.sh ]] &&
    source $(dirname $0)/buildhelpers.sh

Win32BuildSetup=/xbmc/project/Win32BuildSetup
ERRORFILE=$Win32BuildSetup/errormingw
TOUCH=/bin/touch
RM=/bin/rm
NOPROMPT=0
MAKECLEAN=""
MAKEFLAGS=""
TOOLS="mingw"

export _WIN32_WINNT=0x0600
export NTDDI_VERSION=0x06000000

while true; do
  case $1 in
    --tools=* ) TOOLS="${1#*=}"; shift ;;
    --build32=* ) build32="${1#*=}"; shift ;;
    --build64=* ) build64="${1#*=}"; shift ;;
    --prompt=* ) PROMPTLEVEL="${1#*=}"; shift ;;
    --mode=* ) BUILDMODE="${1#*=}"; shift ;;
    -- ) shift; break ;;
    -* ) shift ;;
    * ) break ;;
  esac
done

throwerror() {
  $TOUCH $ERRORFILE
  echo failed to compile $1
  if [ $NOPROMPT == 0 ]; then
	read
  fi
}

setfilepath() {
  FILEPATH=$1
}

checkfiles() {
  for i in $@; do
    if [ ! -f "$FILEPATH/$i" ]; then
      throwerror "$FILEPATH/$i"
      exit 1
    fi
  done
}

buildProcess() {
export PREFIX=/xbmc/project/BuildDependencies/mingwlibs/$ARCHITECTURE
if [ "$(pathChanged $PREFIX /xbmc/tools/buildsteps/windows /xbmc/tools/depends/target/*/*-VERSION)" == "0" ]; then
  return
fi

git clean -dffx $PREFIX
cd /xbmc/tools/buildsteps/windows

# compile our mingw dlls
echo "-------------------------------------------------------------------------------"
echo "compiling mingw libs $BITS"
echo
echo " NOPROMPT  = $NOPROMPT"
echo " MAKECLEAN = $MAKECLEAN"
echo " WORKSPACE = $WORKSPACE"
echo " TOOLCHAIN = $TOOLS"
echo
echo "-------------------------------------------------------------------------------"

echo -ne "\033]0;building FFmpeg $BITS\007"
echo "-------------------------------------------------"
echo " building FFmpeg $BITS"
echo "-------------------------------------------------"
./buildffmpeg.sh
setfilepath $PREFIX/bin
checkfiles avcodec-57.dll avformat-57.dll avutil-55.dll postproc-54.dll swscale-4.dll avfilter-6.dll swresample-2.dll
echo "-------------------------------------------------"
echo " building of FFmpeg $BITS done..."
echo "-------------------------------------------------"

echo -ne "\033]0;building libdvd $BITS\007"
echo "-------------------------------------------------"
echo " building libdvd $BITS"
echo "-------------------------------------------------"
./buildlibdvd.sh
checkfiles libdvdcss-2.dll libdvdnav.dll
echo "-------------------------------------------------"
echo " building of libdvd $BITS done..."
echo "-------------------------------------------------"

echo "-------------------------------------------------------------------------------"
echo
echo "compile mingw libs $BITS done..."
echo
echo "-------------------------------------------------------------------------------"

tagSuccessFulBuild $PREFIX /xbmc/tools/buildsteps/windows /xbmc/tools/depends/target/*/*-VERSION
}

run_builds() {
    new_updates="no"
    new_updates_packages=""
    if [[ $build32 = "yes" ]]; then
        source /local32/etc/profile.local
        buildProcess
        echo "-------------------------------------------------------------------------------"
        echo "compile all libs 32bit done..."
        echo "-------------------------------------------------------------------------------"
    fi

    if [[ $build64 = "yes" ]]; then
        source /local64/etc/profile.local
        buildProcess
        echo "-------------------------------------------------------------------------------"
        echo "compile all libs 64bit done..."
        echo "-------------------------------------------------------------------------------"
    fi
}

# cleanup
if [ -f $ERRORFILE ]; then
  $RM $ERRORFILE
fi

# check for noprompt
if [ "$PROMPTLEVEL" == "noprompt" ]; then
  NOPROMPT=1
fi

if [ "$BUILDMODE" == "clean" ]; then
  MAKECLEAN="clean"
else
  MAKECLEAN="noclean"
fi

run_builds

echo -e "\033]0;compiling done...\007"
echo

# wait for key press
if [ $NOPROMPT == 0 ]; then
  echo press a key to close the window
  read
fi
