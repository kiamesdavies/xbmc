/* header auto-generated by pidl */

#include "librpc/ndr/libndr.h"
#include "autoconf/librpc/gen_ndr/rap.h"

#ifndef _HEADER_NDR_rap
#define _HEADER_NDR_rap

#include "../librpc/ndr/ndr_rap.h"
#define NDR_RAP_NETSHAREENUM (0x00)

#define NDR_RAP_NETSHAREADD (0x01)

#define NDR_RAP_NETSERVERENUM2 (0x02)

#define NDR_RAP_WSERVERGETINFO (0x03)

#define NDR_RAP_NETPRINTQENUM (0x04)

#define NDR_RAP_NETPRINTQGETINFO (0x05)

#define NDR_RAP_NETPRINTJOBPAUSE (0x06)

#define NDR_RAP_NETPRINTJOBCONTINUE (0x07)

#define NDR_RAP_NETPRINTJOBDELETE (0x08)

#define NDR_RAP_NETPRINTQUEUEPAUSE (0x09)

#define NDR_RAP_NETPRINTQUEUERESUME (0x0a)

#define NDR_RAP_NETPRINTQUEUEPURGE (0x0b)

#define NDR_RAP_NETPRINTJOBENUM (0x0c)

#define NDR_RAP_NETPRINTJOBGETINFO (0x0d)

#define NDR_RAP_NETPRINTJOBSETINFO (0x0e)

#define NDR_RAP_NETPRINTDESTENUM (0x0f)

#define NDR_RAP_NETPRINTDESTGETINFO (0x10)

#define NDR_RAP_NETUSERPASSWORDSET2 (0x11)

#define NDR_RAP_NETOEMCHANGEPASSWORD (0x12)

#define NDR_RAP_NETUSERGETINFO (0x13)

#define NDR_RAP_NETSESSIONENUM (0x14)

#define NDR_RAP_NETSESSIONGETINFO (0x15)

#define NDR_RAP_NETUSERADD (0x16)

#define NDR_RAP_NETUSERDELETE (0x17)

#define NDR_RAP_NETREMOTETOD (0x18)

#define NDR_RAP_CALL_COUNT (25)
enum ndr_err_code ndr_push_rap_status(struct ndr_push *ndr, int ndr_flags, enum rap_status r);
enum ndr_err_code ndr_pull_rap_status(struct ndr_pull *ndr, int ndr_flags, enum rap_status *r);
void ndr_print_rap_status(struct ndr_print *ndr, const char *name, enum rap_status r);
void ndr_print_rap_share_info_0(struct ndr_print *ndr, const char *name, const struct rap_share_info_0 *r);
void ndr_print_rap_share_info_1(struct ndr_print *ndr, const char *name, const struct rap_share_info_1 *r);
void ndr_print_rap_share_info_2(struct ndr_print *ndr, const char *name, const struct rap_share_info_2 *r);
void ndr_print_rap_share_info(struct ndr_print *ndr, const char *name, const union rap_share_info *r);
void ndr_print_rap_server_info_0(struct ndr_print *ndr, const char *name, const struct rap_server_info_0 *r);
void ndr_print_rap_server_info_1(struct ndr_print *ndr, const char *name, const struct rap_server_info_1 *r);
void ndr_print_rap_server_info(struct ndr_print *ndr, const char *name, const union rap_server_info *r);
enum ndr_err_code ndr_push_rap_PrintJStatusCode(struct ndr_push *ndr, int ndr_flags, enum rap_PrintJStatusCode r);
enum ndr_err_code ndr_pull_rap_PrintJStatusCode(struct ndr_pull *ndr, int ndr_flags, enum rap_PrintJStatusCode *r);
void ndr_print_rap_PrintJStatusCode(struct ndr_print *ndr, const char *name, enum rap_PrintJStatusCode r);
void ndr_print_rap_PrintJobInfo0(struct ndr_print *ndr, const char *name, const struct rap_PrintJobInfo0 *r);
void ndr_print_rap_PrintJobInfo1(struct ndr_print *ndr, const char *name, const struct rap_PrintJobInfo1 *r);
void ndr_print_rap_PrintJobInfo2(struct ndr_print *ndr, const char *name, const struct rap_PrintJobInfo2 *r);
void ndr_print_rap_PrintJobInfo3(struct ndr_print *ndr, const char *name, const struct rap_PrintJobInfo3 *r);
enum ndr_err_code ndr_push_rap_printj_info(struct ndr_push *ndr, int ndr_flags, const union rap_printj_info *r);
enum ndr_err_code ndr_pull_rap_printj_info(struct ndr_pull *ndr, int ndr_flags, union rap_printj_info *r);
void ndr_print_rap_printj_info(struct ndr_print *ndr, const char *name, const union rap_printj_info *r);
enum ndr_err_code ndr_push_rap_PrintQStatusCode(struct ndr_push *ndr, int ndr_flags, enum rap_PrintQStatusCode r);
enum ndr_err_code ndr_pull_rap_PrintQStatusCode(struct ndr_pull *ndr, int ndr_flags, enum rap_PrintQStatusCode *r);
void ndr_print_rap_PrintQStatusCode(struct ndr_print *ndr, const char *name, enum rap_PrintQStatusCode r);
void ndr_print_rap_PrintQueue0(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue0 *r);
void ndr_print_rap_PrintQueue1(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue1 *r);
void ndr_print_rap_PrintQueue2(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue2 *r);
enum ndr_err_code ndr_push_rap_PrintQueue3(struct ndr_push *ndr, int ndr_flags, const struct rap_PrintQueue3 *r);
enum ndr_err_code ndr_pull_rap_PrintQueue3(struct ndr_pull *ndr, int ndr_flags, struct rap_PrintQueue3 *r);
void ndr_print_rap_PrintQueue3(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue3 *r);
void ndr_print_rap_PrintQueue4(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue4 *r);
void ndr_print_rap_PrintQueue5(struct ndr_print *ndr, const char *name, const struct rap_PrintQueue5 *r);
enum ndr_err_code ndr_push_rap_printq_info(struct ndr_push *ndr, int ndr_flags, const union rap_printq_info *r);
enum ndr_err_code ndr_pull_rap_printq_info(struct ndr_pull *ndr, int ndr_flags, union rap_printq_info *r);
void ndr_print_rap_printq_info(struct ndr_print *ndr, const char *name, const union rap_printq_info *r);
void ndr_print_rap_JobInfoParamNum(struct ndr_print *ndr, const char *name, enum rap_JobInfoParamNum r);
void ndr_print_rap_JobInfoParam(struct ndr_print *ndr, const char *name, const union rap_JobInfoParam *r);
void ndr_print_rap_PrintDest0(struct ndr_print *ndr, const char *name, const struct rap_PrintDest0 *r);
void ndr_print_rap_PrintDest1(struct ndr_print *ndr, const char *name, const struct rap_PrintDest1 *r);
void ndr_print_rap_PrintDest2(struct ndr_print *ndr, const char *name, const struct rap_PrintDest2 *r);
void ndr_print_rap_PrintDest3(struct ndr_print *ndr, const char *name, const struct rap_PrintDest3 *r);
enum ndr_err_code ndr_push_rap_printdest_info(struct ndr_push *ndr, int ndr_flags, const union rap_printdest_info *r);
enum ndr_err_code ndr_pull_rap_printdest_info(struct ndr_pull *ndr, int ndr_flags, union rap_printdest_info *r);
void ndr_print_rap_printdest_info(struct ndr_print *ndr, const char *name, const union rap_printdest_info *r);
void ndr_print_rap_NetUserInfo0(struct ndr_print *ndr, const char *name, const struct rap_NetUserInfo0 *r);
enum ndr_err_code ndr_push_rap_UserPriv(struct ndr_push *ndr, int ndr_flags, enum rap_UserPriv r);
enum ndr_err_code ndr_pull_rap_UserPriv(struct ndr_pull *ndr, int ndr_flags, enum rap_UserPriv *r);
void ndr_print_rap_UserPriv(struct ndr_print *ndr, const char *name, enum rap_UserPriv r);
void ndr_print_rap_NetUserInfo1(struct ndr_print *ndr, const char *name, const struct rap_NetUserInfo1 *r);
enum ndr_err_code ndr_push_rap_AuthFlags(struct ndr_push *ndr, int ndr_flags, enum rap_AuthFlags r);
enum ndr_err_code ndr_pull_rap_AuthFlags(struct ndr_pull *ndr, int ndr_flags, enum rap_AuthFlags *r);
void ndr_print_rap_AuthFlags(struct ndr_print *ndr, const char *name, enum rap_AuthFlags r);
enum ndr_err_code ndr_push_rap_LogonHours(struct ndr_push *ndr, int ndr_flags, const struct rap_LogonHours *r);
enum ndr_err_code ndr_pull_rap_LogonHours(struct ndr_pull *ndr, int ndr_flags, struct rap_LogonHours *r);
void ndr_print_rap_LogonHours(struct ndr_print *ndr, const char *name, const struct rap_LogonHours *r);
void ndr_print_rap_NetUserInfo2(struct ndr_print *ndr, const char *name, const struct rap_NetUserInfo2 *r);
void ndr_print_rap_NetUserInfo10(struct ndr_print *ndr, const char *name, const struct rap_NetUserInfo10 *r);
void ndr_print_rap_NetUserInfo11(struct ndr_print *ndr, const char *name, const struct rap_NetUserInfo11 *r);
enum ndr_err_code ndr_push_rap_netuser_info(struct ndr_push *ndr, int ndr_flags, const union rap_netuser_info *r);
enum ndr_err_code ndr_pull_rap_netuser_info(struct ndr_pull *ndr, int ndr_flags, union rap_netuser_info *r);
void ndr_print_rap_netuser_info(struct ndr_print *ndr, const char *name, const union rap_netuser_info *r);
void ndr_print_rap_session_info_2(struct ndr_print *ndr, const char *name, const struct rap_session_info_2 *r);
enum ndr_err_code ndr_push_rap_session_info(struct ndr_push *ndr, int ndr_flags, const union rap_session_info *r);
enum ndr_err_code ndr_pull_rap_session_info(struct ndr_pull *ndr, int ndr_flags, union rap_session_info *r);
void ndr_print_rap_session_info(struct ndr_print *ndr, const char *name, const union rap_session_info *r);
enum ndr_err_code ndr_push_rap_TimeOfDayInfo(struct ndr_push *ndr, int ndr_flags, const struct rap_TimeOfDayInfo *r);
enum ndr_err_code ndr_pull_rap_TimeOfDayInfo(struct ndr_pull *ndr, int ndr_flags, struct rap_TimeOfDayInfo *r);
void ndr_print_rap_TimeOfDayInfo(struct ndr_print *ndr, const char *name, const struct rap_TimeOfDayInfo *r);
enum ndr_err_code ndr_push_rap_NetShareEnum(struct ndr_push *ndr, int flags, const struct rap_NetShareEnum *r);
enum ndr_err_code ndr_pull_rap_NetShareEnum(struct ndr_pull *ndr, int flags, struct rap_NetShareEnum *r);
void ndr_print_rap_NetShareEnum(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetShareEnum *r);
enum ndr_err_code ndr_push_rap_NetShareAdd(struct ndr_push *ndr, int flags, const struct rap_NetShareAdd *r);
enum ndr_err_code ndr_pull_rap_NetShareAdd(struct ndr_pull *ndr, int flags, struct rap_NetShareAdd *r);
void ndr_print_rap_NetShareAdd(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetShareAdd *r);
enum ndr_err_code ndr_push_rap_NetServerEnum2(struct ndr_push *ndr, int flags, const struct rap_NetServerEnum2 *r);
enum ndr_err_code ndr_pull_rap_NetServerEnum2(struct ndr_pull *ndr, int flags, struct rap_NetServerEnum2 *r);
void ndr_print_rap_NetServerEnum2(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetServerEnum2 *r);
enum ndr_err_code ndr_push_rap_WserverGetInfo(struct ndr_push *ndr, int flags, const struct rap_WserverGetInfo *r);
enum ndr_err_code ndr_pull_rap_WserverGetInfo(struct ndr_pull *ndr, int flags, struct rap_WserverGetInfo *r);
void ndr_print_rap_WserverGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_WserverGetInfo *r);
enum ndr_err_code ndr_push_rap_NetPrintQEnum(struct ndr_push *ndr, int flags, const struct rap_NetPrintQEnum *r);
enum ndr_err_code ndr_pull_rap_NetPrintQEnum(struct ndr_pull *ndr, int flags, struct rap_NetPrintQEnum *r);
void ndr_print_rap_NetPrintQEnum(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintQEnum *r);
enum ndr_err_code ndr_push_rap_NetPrintQGetInfo(struct ndr_push *ndr, int flags, const struct rap_NetPrintQGetInfo *r);
enum ndr_err_code ndr_pull_rap_NetPrintQGetInfo(struct ndr_pull *ndr, int flags, struct rap_NetPrintQGetInfo *r);
void ndr_print_rap_NetPrintQGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintQGetInfo *r);
enum ndr_err_code ndr_push_rap_NetPrintJobPause(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobPause *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobPause(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobPause *r);
void ndr_print_rap_NetPrintJobPause(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobPause *r);
enum ndr_err_code ndr_push_rap_NetPrintJobContinue(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobContinue *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobContinue(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobContinue *r);
void ndr_print_rap_NetPrintJobContinue(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobContinue *r);
enum ndr_err_code ndr_push_rap_NetPrintJobDelete(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobDelete *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobDelete(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobDelete *r);
void ndr_print_rap_NetPrintJobDelete(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobDelete *r);
enum ndr_err_code ndr_push_rap_NetPrintQueuePause(struct ndr_push *ndr, int flags, const struct rap_NetPrintQueuePause *r);
enum ndr_err_code ndr_pull_rap_NetPrintQueuePause(struct ndr_pull *ndr, int flags, struct rap_NetPrintQueuePause *r);
void ndr_print_rap_NetPrintQueuePause(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintQueuePause *r);
enum ndr_err_code ndr_push_rap_NetPrintQueueResume(struct ndr_push *ndr, int flags, const struct rap_NetPrintQueueResume *r);
enum ndr_err_code ndr_pull_rap_NetPrintQueueResume(struct ndr_pull *ndr, int flags, struct rap_NetPrintQueueResume *r);
void ndr_print_rap_NetPrintQueueResume(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintQueueResume *r);
enum ndr_err_code ndr_push_rap_NetPrintQueuePurge(struct ndr_push *ndr, int flags, const struct rap_NetPrintQueuePurge *r);
enum ndr_err_code ndr_pull_rap_NetPrintQueuePurge(struct ndr_pull *ndr, int flags, struct rap_NetPrintQueuePurge *r);
void ndr_print_rap_NetPrintQueuePurge(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintQueuePurge *r);
enum ndr_err_code ndr_push_rap_NetPrintJobEnum(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobEnum *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobEnum(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobEnum *r);
void ndr_print_rap_NetPrintJobEnum(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobEnum *r);
enum ndr_err_code ndr_push_rap_NetPrintJobGetInfo(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobGetInfo *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobGetInfo(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobGetInfo *r);
void ndr_print_rap_NetPrintJobGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobGetInfo *r);
enum ndr_err_code ndr_push_rap_NetPrintJobSetInfo(struct ndr_push *ndr, int flags, const struct rap_NetPrintJobSetInfo *r);
enum ndr_err_code ndr_pull_rap_NetPrintJobSetInfo(struct ndr_pull *ndr, int flags, struct rap_NetPrintJobSetInfo *r);
void ndr_print_rap_NetPrintJobSetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintJobSetInfo *r);
enum ndr_err_code ndr_push_rap_NetPrintDestEnum(struct ndr_push *ndr, int flags, const struct rap_NetPrintDestEnum *r);
enum ndr_err_code ndr_pull_rap_NetPrintDestEnum(struct ndr_pull *ndr, int flags, struct rap_NetPrintDestEnum *r);
void ndr_print_rap_NetPrintDestEnum(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintDestEnum *r);
enum ndr_err_code ndr_push_rap_NetPrintDestGetInfo(struct ndr_push *ndr, int flags, const struct rap_NetPrintDestGetInfo *r);
enum ndr_err_code ndr_pull_rap_NetPrintDestGetInfo(struct ndr_pull *ndr, int flags, struct rap_NetPrintDestGetInfo *r);
void ndr_print_rap_NetPrintDestGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetPrintDestGetInfo *r);
enum ndr_err_code ndr_push_rap_NetUserPasswordSet2(struct ndr_push *ndr, int flags, const struct rap_NetUserPasswordSet2 *r);
enum ndr_err_code ndr_pull_rap_NetUserPasswordSet2(struct ndr_pull *ndr, int flags, struct rap_NetUserPasswordSet2 *r);
void ndr_print_rap_NetUserPasswordSet2(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetUserPasswordSet2 *r);
enum ndr_err_code ndr_push_rap_NetOEMChangePassword(struct ndr_push *ndr, int flags, const struct rap_NetOEMChangePassword *r);
enum ndr_err_code ndr_pull_rap_NetOEMChangePassword(struct ndr_pull *ndr, int flags, struct rap_NetOEMChangePassword *r);
void ndr_print_rap_NetOEMChangePassword(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetOEMChangePassword *r);
enum ndr_err_code ndr_push_rap_NetUserGetInfo(struct ndr_push *ndr, int flags, const struct rap_NetUserGetInfo *r);
enum ndr_err_code ndr_pull_rap_NetUserGetInfo(struct ndr_pull *ndr, int flags, struct rap_NetUserGetInfo *r);
void ndr_print_rap_NetUserGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetUserGetInfo *r);
enum ndr_err_code ndr_push_rap_NetSessionEnum(struct ndr_push *ndr, int flags, const struct rap_NetSessionEnum *r);
enum ndr_err_code ndr_pull_rap_NetSessionEnum(struct ndr_pull *ndr, int flags, struct rap_NetSessionEnum *r);
void ndr_print_rap_NetSessionEnum(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetSessionEnum *r);
enum ndr_err_code ndr_push_rap_NetSessionGetInfo(struct ndr_push *ndr, int flags, const struct rap_NetSessionGetInfo *r);
enum ndr_err_code ndr_pull_rap_NetSessionGetInfo(struct ndr_pull *ndr, int flags, struct rap_NetSessionGetInfo *r);
void ndr_print_rap_NetSessionGetInfo(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetSessionGetInfo *r);
enum ndr_err_code ndr_push_rap_NetUserAdd(struct ndr_push *ndr, int flags, const struct rap_NetUserAdd *r);
enum ndr_err_code ndr_pull_rap_NetUserAdd(struct ndr_pull *ndr, int flags, struct rap_NetUserAdd *r);
void ndr_print_rap_NetUserAdd(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetUserAdd *r);
enum ndr_err_code ndr_push_rap_NetUserDelete(struct ndr_push *ndr, int flags, const struct rap_NetUserDelete *r);
enum ndr_err_code ndr_pull_rap_NetUserDelete(struct ndr_pull *ndr, int flags, struct rap_NetUserDelete *r);
void ndr_print_rap_NetUserDelete(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetUserDelete *r);
enum ndr_err_code ndr_push_rap_NetRemoteTOD(struct ndr_push *ndr, int flags, const struct rap_NetRemoteTOD *r);
enum ndr_err_code ndr_pull_rap_NetRemoteTOD(struct ndr_pull *ndr, int flags, struct rap_NetRemoteTOD *r);
void ndr_print_rap_NetRemoteTOD(struct ndr_print *ndr, const char *name, int flags, const struct rap_NetRemoteTOD *r);
#endif /* _HEADER_NDR_rap */
