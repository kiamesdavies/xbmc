/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Type cast for the gethostbyname() argument */
/* #undef GETHOSTBYNAME_ARG_CAST */

/* Define to 1 if you have the <ansidecl.h> header file. */
/* #undef HAVE_ANSIDECL_H */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H

/* Define to 1 if you have the <arpa/nameser.h> header file. */
#define HAVE_ARPA_NAMESER_H

/* Whether struct sockaddr::__ss_family exists */
/* #undef HAVE_BROKEN_SS_FAMILY */

/* Define to 1 if you have the `class' function. */
/* #undef HAVE_CLASS */

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H

/* Define to 1 if you have the <dirent.h> header file. */
#define HAVE_DIRENT_H

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H

/* Have dlopen based dso */
/* #undef HAVE_DLOPEN */

/* Define to 1 if you have the <dl.h> header file. */
/* #undef HAVE_DL_H */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H

/* Define to 1 if you have the `finite' function. */
/* #undef HAVE_FINITE */

/* Define to 1 if you have the <float.h> header file. */
#define HAVE_FLOAT_H

/* Define to 1 if you have the `fpclass' function. */
/* #undef HAVE_FPCLASS */

/* Define to 1 if you have the `fprintf' function. */
#define HAVE_FPRINTF

/* Define to 1 if you have the `fp_class' function. */
/* #undef HAVE_FP_CLASS */

/* Define to 1 if you have the <fp_class.h> header file. */
/* #undef HAVE_FP_CLASS_H */

/* Define to 1 if you have the `ftime' function. */
/* #undef HAVE_FTIME */

/* Define if getaddrinfo is there */
#define HAVE_GETADDRINFO

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H

/* Define to 1 if you have the `isascii' function. */
#define HAVE_ISASCII

/* Define if isinf is there */
#define HAVE_ISINF

/* Define if isnan is there */
#define HAVE_ISNAN

/* Define to 1 if you have the `isnand' function. */
/* #undef HAVE_ISNAND */

/* Define if history library is there (-lhistory) */
/* #undef HAVE_LIBHISTORY */

/* Have compression library */
/* #undef HAVE_LIBLZMA */

/* Define if pthread library is there (-lpthread) */
/* #undef HAVE_LIBPTHREAD */

/* Define if readline library is there (-lreadline) */
/* #undef HAVE_LIBREADLINE */

/* Have compression library */
/* #undef HAVE_LIBZ */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H

/* Define to 1 if you have the `localtime' function. */
#define HAVE_LOCALTIME

/* Define to 1 if you have the <lzma.h> header file. */
/* #undef HAVE_LZMA_H */

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H

/* Define to 1 if you have the <math.h> header file. */
#define HAVE_MATH_H

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H

/* Define to 1 if you have the `mmap' function. */
#define HAVE_MMAP

/* Define to 1 if you have the `munmap' function. */
#define HAVE_MUNMAP

/* mmap() is no good without munmap() */
#if defined(HAVE_MMAP) && !defined(HAVE_MUNMAP)
#  undef /**/ HAVE_MMAP
#endif

/* Define to 1 if you have the <nan.h> header file. */
/* #undef HAVE_NAN_H */

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H

/* Define to 1 if you have the <poll.h> header file. */
#define HAVE_POLL_H

/* Define to 1 if you have the `printf' function. */
#define HAVE_PRINTF

/* Define if <pthread.h> is there */
/* #undef HAVE_PTHREAD_H */

/* Define to 1 if you have the `putenv' function. */
#define HAVE_PUTENV

/* Define to 1 if you have the `rand' function. */
#define HAVE_RAND

/* Define to 1 if you have the `rand_r' function. */
#define HAVE_RAND_R

/* Define to 1 if you have the <resolv.h> header file. */
#define HAVE_RESOLV_H

/* Have shl_load based dso */
/* #undef HAVE_SHLLOAD */

/* Define to 1 if you have the `signal' function. */
#define HAVE_SIGNAL

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF

/* Define to 1 if you have the `sprintf' function. */
#define HAVE_SPRINTF

/* Define to 1 if you have the `srand' function. */
#define HAVE_SRAND

/* Define to 1 if you have the `sscanf' function. */
#define HAVE_SSCANF

/* Define to 1 if you have the `stat' function. */
#define HAVE_STAT

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H

/* Define to 1 if you have the `strndup' function. */
#define HAVE_STRNDUP

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/timeb.h> header file. */
/* #undef HAVE_SYS_TIMEB_H */

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H

/* Define to 1 if you have the `time' function. */
#define HAVE_TIME

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H

/* Whether va_copy() is available */
#define HAVE_VA_COPY

/* Define to 1 if you have the `vfprintf' function. */
#define HAVE_VFPRINTF

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF

/* Define to 1 if you have the `vsprintf' function. */
#define HAVE_VSPRINTF

/* Define to 1 if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H

/* Define to 1 if you have the `_stat' function. */
/* #undef HAVE__STAT */

/* Whether __va_copy() is available */
#define HAVE___VA_COPY

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST

/* Define to the sub-directory where libtool stores uninstalled libraries. */
/* #undef LT_OBJDIR */

/* Name of package */
/* #undef PACKAGE */

/* Define to the address where bug reports for this package should be sent. */
/* #undef PACKAGE_BUGREPORT */

/* Define to the full name of this package. */
/* #undef PACKAGE_NAME */

/* Define to the full name and version of this package. */
/* #undef PACKAGE_STRING */

/* Define to the one symbol short name of this package. */
/* #undef PACKAGE_TARNAME */

/* Define to the home page for this package. */
/* #undef PACKAGE_URL */

/* Define to the version of this package. */
/* #undef PACKAGE_VERSION */

/* Type cast for the send() function 2nd arg */
/* #undef SEND_ARG2_CAST */

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Support for IPv6 */
/* #undef SUPPORT_IP6 */

/* Define if va_list is an array type */
/* #undef VA_LIST_IS_ARRAY */

/* Version number of package */
#define VERSION

/* Determine what socket length (socklen_t) data type is */
/* #undef XML_SOCKLEN_T */

/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT32_T */

/* Using the Win32 Socket implementation */
/* #undef _WINSOCKAPI_ */

/* ss_family is not defined here, use __ss_family instead */
/* #undef ss_family */

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint32_t */
