/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Type cast for the gethostbyname() argument */
#cmakedefine GETHOSTBYNAME_ARG_CAST

/* Define to 1 if you have the <ansidecl.h> header file. */
#cmakedefine HAVE_ANSIDECL_H

/* Define to 1 if you have the <arpa/inet.h> header file. */
#cmakedefine HAVE_ARPA_INET_H

/* Define to 1 if you have the <arpa/nameser.h> header file. */
#cmakedefine HAVE_ARPA_NAMESER_H

/* Whether struct sockaddr::__ss_family exists */
#cmakedefine HAVE_BROKEN_SS_FAMILY

/* Define to 1 if you have the `class' function. */
#cmakedefine HAVE_CLASS

/* Define to 1 if you have the <ctype.h> header file. */
#cmakedefine HAVE_CTYPE_H

/* Define to 1 if you have the <dirent.h> header file. */
#cmakedefine HAVE_DIRENT_H

/* Define to 1 if you have the <dlfcn.h> header file. */
#cmakedefine HAVE_DLFCN_H

/* Have dlopen based dso */
#cmakedefine HAVE_DLOPEN

/* Define to 1 if you have the <dl.h> header file. */
#cmakedefine HAVE_DL_H

/* Define to 1 if you have the <errno.h> header file. */
#cmakedefine HAVE_ERRNO_H

/* Define to 1 if you have the <fcntl.h> header file. */
#cmakedefine HAVE_FCNTL_H

/* Define to 1 if you have the `finite' function. */
#cmakedefine HAVE_FINITE

/* Define to 1 if you have the <float.h> header file. */
#cmakedefine HAVE_FLOAT_H

/* Define to 1 if you have the `fpclass' function. */
#cmakedefine HAVE_FPCLASS

/* Define to 1 if you have the `fprintf' function. */
#cmakedefine HAVE_FPRINTF

/* Define to 1 if you have the `fp_class' function. */
#cmakedefine HAVE_FP_CLASS

/* Define to 1 if you have the <fp_class.h> header file. */
#cmakedefine HAVE_FP_CLASS_H

/* Define to 1 if you have the `ftime' function. */
#cmakedefine HAVE_FTIME

/* Define if getaddrinfo is there */
#cmakedefine HAVE_GETADDRINFO

/* Define to 1 if you have the `gettimeofday' function. */
#cmakedefine HAVE_GETTIMEOFDAY

/* Define to 1 if you have the <ieeefp.h> header file. */
#cmakedefine HAVE_IEEEFP_H

/* Define to 1 if you have the <inttypes.h> header file. */
#cmakedefine HAVE_INTTYPES_H

/* Define to 1 if you have the `isascii' function. */
#cmakedefine HAVE_ISASCII

/* Define if isinf is there */
#cmakedefine HAVE_ISINF

/* Define if isnan is there */
#cmakedefine HAVE_ISNAN

/* Define to 1 if you have the `isnand' function. */
#cmakedefine HAVE_ISNAND

/* Define if history library is there (-lhistory) */
#cmakedefine HAVE_LIBHISTORY

/* Have compression library */
#cmakedefine HAVE_LIBLZMA

/* Define if pthread library is there (-lpthread) */
#cmakedefine HAVE_LIBPTHREAD

/* Define if readline library is there (-lreadline) */
#cmakedefine HAVE_LIBREADLINE

/* Have compression library */
#cmakedefine HAVE_LIBZ

/* Define to 1 if you have the <limits.h> header file. */
#cmakedefine HAVE_LIMITS_H

/* Define to 1 if you have the `localtime' function. */
#cmakedefine HAVE_LOCALTIME

/* Define to 1 if you have the <lzma.h> header file. */
#cmakedefine HAVE_LZMA_H

/* Define to 1 if you have the <malloc.h> header file. */
#cmakedefine HAVE_MALLOC_H

/* Define to 1 if you have the <math.h> header file. */
#cmakedefine HAVE_MATH_H

/* Define to 1 if you have the <memory.h> header file. */
#cmakedefine HAVE_MEMORY_H

/* Define to 1 if you have the `mmap' function. */
#cmakedefine HAVE_MMAP

/* Define to 1 if you have the `munmap' function. */
#cmakedefine HAVE_MUNMAP

/* mmap() is no good without munmap() */
#if defined(HAVE_MMAP) && !defined(HAVE_MUNMAP)
#  undef /**/ HAVE_MMAP
#endif

/* Define to 1 if you have the <nan.h> header file. */
#cmakedefine HAVE_NAN_H

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
#cmakedefine HAVE_NDIR_H

/* Define to 1 if you have the <netdb.h> header file. */
#cmakedefine HAVE_NETDB_H

/* Define to 1 if you have the <netinet/in.h> header file. */
#cmakedefine HAVE_NETINET_IN_H

/* Define to 1 if you have the <poll.h> header file. */
#cmakedefine HAVE_POLL_H

/* Define to 1 if you have the `printf' function. */
#cmakedefine HAVE_PRINTF

/* Define if <pthread.h> is there */
#cmakedefine HAVE_PTHREAD_H

/* Define to 1 if you have the `putenv' function. */
#cmakedefine HAVE_PUTENV

/* Define to 1 if you have the `rand' function. */
#cmakedefine HAVE_RAND

/* Define to 1 if you have the `rand_r' function. */
#cmakedefine HAVE_RAND_R

/* Define to 1 if you have the <resolv.h> header file. */
#cmakedefine HAVE_RESOLV_H

/* Have shl_load based dso */
#cmakedefine HAVE_SHLLOAD

/* Define to 1 if you have the `signal' function. */
#cmakedefine HAVE_SIGNAL

/* Define to 1 if you have the <signal.h> header file. */
#cmakedefine HAVE_SIGNAL_H

/* Define to 1 if you have the `snprintf' function. */
#cmakedefine HAVE_SNPRINTF

/* Define to 1 if you have the `sprintf' function. */
#cmakedefine HAVE_SPRINTF

/* Define to 1 if you have the `srand' function. */
#cmakedefine HAVE_SRAND

/* Define to 1 if you have the `sscanf' function. */
#cmakedefine HAVE_SSCANF

/* Define to 1 if you have the `stat' function. */
#cmakedefine HAVE_STAT

/* Define to 1 if you have the <stdarg.h> header file. */
#cmakedefine HAVE_STDARG_H

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#cmakedefine HAVE_STDLIB_H

/* Define to 1 if you have the `strdup' function. */
#cmakedefine HAVE_STRDUP

/* Define to 1 if you have the `strerror' function. */
#cmakedefine HAVE_STRERROR

/* Define to 1 if you have the `strftime' function. */
#cmakedefine HAVE_STRFTIME

/* Define to 1 if you have the <strings.h> header file. */
#cmakedefine HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#cmakedefine HAVE_STRING_H

/* Define to 1 if you have the `strndup' function. */
#cmakedefine HAVE_STRNDUP

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
#cmakedefine HAVE_SYS_DIR_H

/* Define to 1 if you have the <sys/mman.h> header file. */
#cmakedefine HAVE_SYS_MMAN_H

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
#cmakedefine HAVE_SYS_NDIR_H

/* Define to 1 if you have the <sys/select.h> header file. */
#cmakedefine HAVE_SYS_SELECT_H

/* Define to 1 if you have the <sys/socket.h> header file. */
#cmakedefine HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#cmakedefine HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/timeb.h> header file. */
#cmakedefine HAVE_SYS_TIMEB_H

/* Define to 1 if you have the <sys/time.h> header file. */
#cmakedefine HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H

/* Define to 1 if you have the `time' function. */
#cmakedefine HAVE_TIME

/* Define to 1 if you have the <time.h> header file. */
#cmakedefine HAVE_TIME_H

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H

/* Whether va_copy() is available */
#cmakedefine HAVE_VA_COPY

/* Define to 1 if you have the `vfprintf' function. */
#cmakedefine HAVE_VFPRINTF

/* Define to 1 if you have the `vsnprintf' function. */
#cmakedefine HAVE_VSNPRINTF

/* Define to 1 if you have the `vsprintf' function. */
#cmakedefine HAVE_VSPRINTF

/* Define to 1 if you have the <zlib.h> header file. */
#cmakedefine HAVE_ZLIB_H

/* Define to 1 if you have the `_stat' function. */
#cmakedefine HAVE__STAT

/* Whether __va_copy() is available */
#cmakedefine HAVE___VA_COPY

/* Define as const if the declaration of iconv() needs const. */
#cmakedefine ICONV_CONST

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#cmakedefine LT_OBJDIR

/* Name of package */
#cmakedefine PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#cmakedefine PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#cmakedefine PACKAGE_NAME

/* Define to the full name and version of this package. */
#cmakedefine PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#cmakedefine PACKAGE_TARNAME

/* Define to the home page for this package. */
#cmakedefine PACKAGE_URL

/* Define to the version of this package. */
#cmakedefine PACKAGE_VERSION

/* Type cast for the send() function 2nd arg */
#cmakedefine SEND_ARG2_CAST

/* Define to 1 if you have the ANSI C header files. */
#cmakedefine STDC_HEADERS

/* Support for IPv6 */
#cmakedefine SUPPORT_IP6

/* Define if va_list is an array type */
#cmakedefine VA_LIST_IS_ARRAY

/* Version number of package */
#cmakedefine VERSION

/* Determine what socket length (socklen_t) data type is */
#cmakedefine XML_SOCKLEN_T

/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
#cmakedefine _UINT32_T

/* Using the Win32 Socket implementation */
#cmakedefine _WINSOCKAPI_

/* ss_family is not defined here, use __ss_family instead */
#cmakedefine ss_family

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
#cmakedefine uint32_t
