/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_drsblobs
#define _PIDL_HEADER_drsblobs

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/drsuapi.h"
#include "librpc/gen_ndr/misc.h"
#include "librpc/gen_ndr/samr.h"
#include "librpc/gen_ndr/lsa.h"
#include "librpc/gen_ndr/security.h"
#ifndef _HEADER_drsblobs
#define _HEADER_drsblobs

#define SUPPLEMENTAL_CREDENTIALS_PREFIX	( "                                                " )
struct replPropertyMetaData1 {
	enum drsuapi_DsAttributeId attid;
	uint32_t version;
	NTTIME originating_change_time;
	struct GUID originating_invocation_id;
	uint64_t originating_usn;
	uint64_t local_usn;
};

struct replPropertyMetaDataCtr1 {
	uint32_t count;
	uint32_t reserved;/* [value(0)] */
	struct replPropertyMetaData1 *array;
};

union replPropertyMetaDataCtr {
	struct replPropertyMetaDataCtr1 ctr1;/* [case] */
}/* [nodiscriminant] */;

struct replPropertyMetaDataBlob {
	uint32_t version;
	uint32_t reserved;/* [value(0)] */
	union replPropertyMetaDataCtr ctr;/* [switch_is(version)] */
}/* [public] */;

struct replUpToDateVectorCtr1 {
	uint32_t count;
	uint32_t reserved;/* [value(0)] */
	struct drsuapi_DsReplicaCursor *cursors;
};

struct replUpToDateVectorCtr2 {
	uint32_t count;
	uint32_t reserved;/* [value(0)] */
	struct drsuapi_DsReplicaCursor2 *cursors;
};

union replUpToDateVectorCtr {
	struct replUpToDateVectorCtr1 ctr1;/* [case] */
	struct replUpToDateVectorCtr2 ctr2;/* [case(2)] */
}/* [nodiscriminant] */;

struct replUpToDateVectorBlob {
	uint32_t version;
	uint32_t reserved;/* [value(0)] */
	union replUpToDateVectorCtr ctr;/* [switch_is(version)] */
}/* [public] */;

struct repsFromTo1OtherInfo {
	uint32_t __dns_name_size;/* [value(strlen(dns_name)+1)] */
	const char *dns_name;/* [charset(DOS)] */
}/* [gensize,public] */;

struct repsFromTo1 {
	uint32_t blobsize;/* [value(ndr_size_repsFromTo1(this,ndr->flags)+8)] */
	uint32_t consecutive_sync_failures;
	NTTIME last_success;
	NTTIME last_attempt;
	WERROR result_last_attempt;
	struct repsFromTo1OtherInfo *other_info;/* [relative] */
	uint32_t other_info_length;/* [value(ndr_size_repsFromTo1OtherInfo(other_info,ndr->flags))] */
	uint32_t replica_flags;
	uint8_t schedule[84];
	uint32_t reserved;/* [value(0)] */
	struct drsuapi_DsReplicaHighWaterMark highwatermark;
	struct GUID source_dsa_obj_guid;
	struct GUID source_dsa_invocation_id;
	struct GUID transport_guid;
}/* [public,gensize,flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct repsFromTo2OtherInfo {
	uint32_t __ndr_size;/* [value(ndr_size_repsFromTo2OtherInfo(this,ndr->flags))] */
	const char * dns_name1;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative] */
	uint32_t unknown1;
	const char * dns_name2;/* [relative,flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2)] */
	uint64_t unknown2;
}/* [gensize,public,relative_base] */;

struct repsFromTo2 {
	uint32_t blobsize;/* [value(ndr_size_repsFromTo2(this,ndr->flags)+8)] */
	uint32_t consecutive_sync_failures;
	NTTIME last_success;
	NTTIME last_attempt;
	WERROR result_last_attempt;
	struct repsFromTo2OtherInfo *other_info;/* [relative] */
	uint32_t other_info_length;/* [value(ndr_size_repsFromTo2OtherInfo(other_info,ndr->flags))] */
	uint32_t replica_flags;
	uint8_t schedule[84];
	uint32_t reserved;/* [value(0)] */
	struct drsuapi_DsReplicaHighWaterMark highwatermark;
	struct GUID source_dsa_obj_guid;
	struct GUID source_dsa_invocation_id;
	struct GUID transport_guid;
	uint64_t unknown1;
}/* [flag(LIBNDR_PRINT_ARRAY_HEX),gensize,public] */;

union repsFromTo {
	struct repsFromTo1 ctr1;/* [case] */
	struct repsFromTo2 ctr2;/* [case(2)] */
}/* [nodiscriminant] */;

struct repsFromToBlob {
	uint32_t version;
	uint32_t reserved;/* [value(0)] */
	union repsFromTo ctr;/* [switch_is(version)] */
}/* [public] */;

struct scheduleHeader {
	uint32_t type;/* [value(0)] */
	uint32_t offset;
}/* [public] */;

struct scheduleSlots {
	uint8_t slots[168];
}/* [public] */;

struct schedule {
	uint32_t size;
	uint32_t bandwidth;/* [value(0)] */
	uint32_t numberOfSchedules;/* [value] */
	struct scheduleHeader *headerArray;
	struct scheduleSlots *dataArray;
}/* [public] */;

struct partialAttributeSetCtr1 {
	uint32_t count;
	enum drsuapi_DsAttributeId *array;
};

union partialAttributeSetCtr {
	struct partialAttributeSetCtr1 ctr1;/* [case] */
}/* [nodiscriminant] */;

struct partialAttributeSetBlob {
	uint32_t version;
	uint32_t reserved;/* [value(0)] */
	union partialAttributeSetCtr ctr;/* [switch_is(version)] */
}/* [public] */;

struct schemaInfoBlob {
	uint8_t marker;/* [value(0xFF)] */
	uint32_t revision;/* [flag(LIBNDR_FLAG_BIGENDIAN)] */
	struct GUID invocation_id;
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;

struct drsuapi_MSPrefixMap_Entry {
	uint16_t entryID;
	uint16_t length;
	uint8_t *binary_oid;
}/* [noprint,flag(LIBNDR_FLAG_NOALIGN)] */;

struct drsuapi_MSPrefixMap_Ctr {
	uint32_t num_entries;
	uint32_t __ndr_size;/* [value(ndr_size_drsuapi_MSPrefixMap_Ctr(r,ndr->flags))] */
	struct drsuapi_MSPrefixMap_Entry *entries;
}/* [gensize,public] */;

enum prefixMapVersion
#ifndef USE_UINT_ENUMS
 {
	PREFIX_MAP_VERSION_DSDB=(int)(0x44534442)
}
#else
 { __do_not_use_enum_prefixMapVersion=0x7FFFFFFF}
#define PREFIX_MAP_VERSION_DSDB ( 0x44534442 )
#endif
;

union prefixMapCtr {
	struct drsuapi_DsReplicaOIDMapping_Ctr dsdb;/* [case(PREFIX_MAP_VERSION_DSDB)] */
}/* [nodiscriminant] */;

struct prefixMapBlob {
	enum prefixMapVersion version;
	uint32_t reserved;/* [value(0)] */
	union prefixMapCtr ctr;/* [switch_is(version)] */
}/* [public] */;

union ldapControlDirSyncExtra {
	struct replUpToDateVectorBlob uptodateness_vector;/* [default] */
}/* [nodiscriminant,gensize] */;

struct ldapControlDirSyncBlob {
	uint32_t u1;/* [value(3)] */
	NTTIME time;
	uint32_t u2;
	uint32_t u3;
	uint32_t extra_length;/* [value(ndr_size_ldapControlDirSyncExtra(&extra,extra.uptodateness_vector.version,0))] */
	struct drsuapi_DsReplicaHighWaterMark highwatermark;
	struct GUID guid1;
	union ldapControlDirSyncExtra extra;/* [switch_is(extra_length)] */
};

struct ldapControlDirSyncCookie {
	const char *msds;/* [value("MSDS"),charset(DOS)] */
	struct ldapControlDirSyncBlob blob;/* [subcontext(0)] */
}/* [public,relative_base] */;

struct supplementalCredentialsPackage {
	uint16_t name_len;/* [value(2*strlen_m(name))] */
	uint16_t data_len;/* [value(strlen(data))] */
	uint16_t reserved;
	const char *name;/* [charset(UTF16)] */
	const char *data;/* [charset(DOS)] */
};

enum supplementalCredentialsSignature
#ifndef USE_UINT_ENUMS
 {
	SUPPLEMENTAL_CREDENTIALS_SIGNATURE=(int)(0x0050)
}
#else
 { __do_not_use_enum_supplementalCredentialsSignature=0x7FFFFFFF}
#define SUPPLEMENTAL_CREDENTIALS_SIGNATURE ( 0x0050 )
#endif
;

struct supplementalCredentialsSubBlob {
	const char *prefix;/* [charset(UTF16),value(SUPPLEMENTAL_CREDENTIALS_PREFIX)] */
	enum supplementalCredentialsSignature signature;/* [value(SUPPLEMENTAL_CREDENTIALS_SIGNATURE)] */
	uint16_t num_packages;
	struct supplementalCredentialsPackage *packages;
}/* [gensize] */;

struct supplementalCredentialsBlob {
	uint32_t unknown1;/* [value(0)] */
	uint32_t __ndr_size;/* [value(ndr_size_supplementalCredentialsSubBlob(&sub,ndr->flags))] */
	uint32_t unknown2;/* [value(0)] */
	struct supplementalCredentialsSubBlob sub;/* [subcontext_size(__ndr_size),subcontext(0)] */
	uint8_t unknown3;/* [value(0)] */
}/* [public] */;

struct package_PackagesBlob {
	const char ** names;/* [flag(LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING)] */
}/* [public] */;

struct package_PrimaryKerberosString {
	uint16_t length;/* [value(2*strlen_m(string))] */
	uint16_t size;/* [value(2*strlen_m(string))] */
	const char * string;/* [subcontext_size(size),relative,flag(LIBNDR_FLAG_STR_NOTERM|LIBNDR_FLAG_REMAINING),subcontext(0)] */
};

struct package_PrimaryKerberosKey3 {
	uint16_t reserved1;/* [value(0)] */
	uint16_t reserved2;/* [value(0)] */
	uint32_t reserved3;/* [value(0)] */
	uint32_t keytype;
	uint32_t value_len;/* [value((value?value->length:0))] */
	DATA_BLOB *value;/* [flag(LIBNDR_FLAG_REMAINING),subcontext(0),subcontext_size(value_len),relative] */
};

struct package_PrimaryKerberosCtr3 {
	uint16_t num_keys;
	uint16_t num_old_keys;
	struct package_PrimaryKerberosString salt;
	struct package_PrimaryKerberosKey3 *keys;
	struct package_PrimaryKerberosKey3 *old_keys;
	uint32_t padding1;/* [value(0)] */
	uint32_t padding2;/* [value(0)] */
	uint32_t padding3;/* [value(0)] */
	uint32_t padding4;/* [value(0)] */
	uint32_t padding5;/* [value(0)] */
};

struct package_PrimaryKerberosKey4 {
	uint16_t reserved1;/* [value(0)] */
	uint16_t reserved2;/* [value(0)] */
	uint32_t reserved3;/* [value(0)] */
	uint32_t iteration_count;
	uint32_t keytype;
	uint32_t value_len;/* [value((value?value->length:0))] */
	DATA_BLOB *value;/* [flag(LIBNDR_FLAG_REMAINING),subcontext(0),subcontext_size(value_len),relative] */
};

struct package_PrimaryKerberosCtr4 {
	uint16_t num_keys;
	uint16_t num_service_keys;/* [value(0)] */
	uint16_t num_old_keys;
	uint16_t num_older_keys;
	struct package_PrimaryKerberosString salt;
	uint32_t default_iteration_count;
	struct package_PrimaryKerberosKey4 *keys;
	struct package_PrimaryKerberosKey4 *service_keys;
	struct package_PrimaryKerberosKey4 *old_keys;
	struct package_PrimaryKerberosKey4 *older_keys;
};

union package_PrimaryKerberosCtr {
	struct package_PrimaryKerberosCtr3 ctr3;/* [case(3)] */
	struct package_PrimaryKerberosCtr4 ctr4;/* [case(4)] */
}/* [nodiscriminant] */;

struct package_PrimaryKerberosBlob {
	uint16_t version;
	uint16_t flags;/* [value(0)] */
	union package_PrimaryKerberosCtr ctr;/* [switch_is(version)] */
}/* [public] */;

struct package_PrimaryCLEARTEXTBlob {
	DATA_BLOB cleartext;/* [flag(LIBNDR_FLAG_REMAINING)] */
}/* [public] */;

struct package_PrimaryWDigestHash {
	uint8_t hash[16];
}/* [flag(LIBNDR_PRINT_ARRAY_HEX)] */;

struct package_PrimaryWDigestBlob {
	uint16_t unknown1;/* [value(0x31)] */
	uint8_t unknown2;/* [value(0x01)] */
	uint8_t num_hashes;
	uint32_t unknown3;/* [value(0)] */
	uint64_t uuknown4;/* [value(0)] */
	struct package_PrimaryWDigestHash *hashes;
}/* [public] */;

struct AuthInfoNone {
	uint32_t size;/* [value(0)] */
};

struct AuthInfoNT4Owf {
	uint32_t size;/* [value(16)] */
	struct samr_Password password;
};

struct AuthInfoClear {
	uint32_t size;
	uint8_t *password;
};

struct AuthInfoVersion {
	uint32_t size;/* [value(4)] */
	uint32_t version;
};

union AuthInfo {
	struct AuthInfoNone none;/* [case(TRUST_AUTH_TYPE_NONE)] */
	struct AuthInfoNT4Owf nt4owf;/* [case(TRUST_AUTH_TYPE_NT4OWF)] */
	struct AuthInfoClear clear;/* [case(TRUST_AUTH_TYPE_CLEAR)] */
	struct AuthInfoVersion version;/* [case(TRUST_AUTH_TYPE_VERSION)] */
}/* [nodiscriminant] */;

struct AuthenticationInformation {
	NTTIME LastUpdateTime;
	enum lsa_TrustAuthType AuthType;
	union AuthInfo AuthInfo;/* [switch_is(AuthType)] */
	DATA_BLOB _pad;/* [flag(LIBNDR_FLAG_ALIGN4)] */
}/* [public] */;

struct AuthenticationInformationArray {
	uint32_t count;
	struct AuthenticationInformation *array;
}/* [gensize,public,nopull,nopush] */;

struct trustAuthInOutBlob {
	uint32_t count;
	uint32_t current_offset;/* [value((count>0)?12:0)] */
	uint32_t previous_offset;/* [value((count>0)?12+ndr_size_AuthenticationInformationArray(&current,ndr->flags):0)] */
	struct AuthenticationInformationArray current;/* [subcontext(0),subcontext_size((previous_offset)-(current_offset))] */
	struct AuthenticationInformationArray previous;/* [flag(LIBNDR_FLAG_REMAINING),subcontext(0)] */
}/* [gensize,public,nopush] */;

struct trustDomainPasswords {
	uint8_t confounder[512];
	struct trustAuthInOutBlob outgoing;/* [subcontext_size(outgoing_size),subcontext(0)] */
	struct trustAuthInOutBlob incoming;/* [subcontext(0),subcontext_size(incoming_size)] */
	uint32_t outgoing_size;/* [value(ndr_size_trustAuthInOutBlob(&outgoing,ndr->flags))] */
	uint32_t incoming_size;/* [value(ndr_size_trustAuthInOutBlob(&incoming,ndr->flags))] */
}/* [nopull,public] */;

struct DsCompressedChunk {
	uint32_t marker;
	DATA_BLOB data;
}/* [public] */;

struct ExtendedErrorAString {
	uint16_t __size;
	const char *string;/* [size_is(__size),unique,charset(DOS)] */
};

struct ExtendedErrorUString {
	uint16_t __size;
	const char *string;/* [size_is(__size),charset(UTF16),unique] */
};

struct ExtendedErrorBlob {
	uint16_t length;
	uint8_t *data;/* [size_is(length),unique] */
};

enum ExtendedErrorComputerNamePresent
#ifndef USE_UINT_ENUMS
 {
	EXTENDED_ERROR_COMPUTER_NAME_PRESENT=(int)(1),
	EXTENDED_ERROR_COMPUTER_NAME_NOT_PRESENT=(int)(2)
}
#else
 { __do_not_use_enum_ExtendedErrorComputerNamePresent=0x7FFFFFFF}
#define EXTENDED_ERROR_COMPUTER_NAME_PRESENT ( 1 )
#define EXTENDED_ERROR_COMPUTER_NAME_NOT_PRESENT ( 2 )
#endif
;

union ExtendedErrorComputerNameU {
	struct ExtendedErrorUString name;/* [case(EXTENDED_ERROR_COMPUTER_NAME_PRESENT)] */
}/* [switch_type(ExtendedErrorComputerNamePresent)] */;

struct ExtendedErrorComputerName {
	enum ExtendedErrorComputerNamePresent present;
	union ExtendedErrorComputerNameU n;/* [switch_is(present)] */
};

enum ExtendedErrorParamType
#ifndef USE_UINT_ENUMS
 {
	EXTENDED_ERROR_PARAM_TYPE_ASCII_STRING=(int)(1),
	EXTENDED_ERROR_PARAM_TYPE_UNICODE_STRING=(int)(2),
	EXTENDED_ERROR_PARAM_TYPE_UINT32=(int)(3),
	EXTENDED_ERROR_PARAM_TYPE_UINT16=(int)(4),
	EXTENDED_ERROR_PARAM_TYPE_UINT64=(int)(5),
	EXTENDED_ERROR_PARAM_TYPE_NONE=(int)(6),
	EXTENDED_ERROR_PARAM_TYPE_BLOB=(int)(7)
}
#else
 { __do_not_use_enum_ExtendedErrorParamType=0x7FFFFFFF}
#define EXTENDED_ERROR_PARAM_TYPE_ASCII_STRING ( 1 )
#define EXTENDED_ERROR_PARAM_TYPE_UNICODE_STRING ( 2 )
#define EXTENDED_ERROR_PARAM_TYPE_UINT32 ( 3 )
#define EXTENDED_ERROR_PARAM_TYPE_UINT16 ( 4 )
#define EXTENDED_ERROR_PARAM_TYPE_UINT64 ( 5 )
#define EXTENDED_ERROR_PARAM_TYPE_NONE ( 6 )
#define EXTENDED_ERROR_PARAM_TYPE_BLOB ( 7 )
#endif
;

union ExtendedErrorParamU {
	struct ExtendedErrorAString a_string;/* [case(EXTENDED_ERROR_PARAM_TYPE_ASCII_STRING)] */
	struct ExtendedErrorUString u_string;/* [case(EXTENDED_ERROR_PARAM_TYPE_UNICODE_STRING)] */
	uint32_t uint32;/* [case(EXTENDED_ERROR_PARAM_TYPE_UINT32)] */
	uint16_t uint16;/* [case(EXTENDED_ERROR_PARAM_TYPE_UINT16)] */
	uint64_t uint64;/* [case(EXTENDED_ERROR_PARAM_TYPE_UINT64)] */
	struct ExtendedErrorBlob blob;/* [case(EXTENDED_ERROR_PARAM_TYPE_BLOB)] */
}/* [switch_type(ExtendedErrorParamType)] */;

struct ExtendedErrorParam {
	enum ExtendedErrorParamType type;
	union ExtendedErrorParamU p;/* [switch_is(type)] */
};

struct ExtendedErrorInfo {
	struct ExtendedErrorInfo *next;/* [unique] */
	struct ExtendedErrorComputerName computer_name;
	uint64_t pid;
	NTTIME time;
	uint32_t generating_component;
	WERROR status;
	uint16_t detection_location;
	uint16_t flags;
	uint16_t num_params;
	struct ExtendedErrorParam *params;/* [size_is(num_params)] */
}/* [public] */;

struct ExtendedErrorInfoPtr {
	struct ExtendedErrorInfo *info;/* [unique] */
};

struct ForestTrustString {
	uint32_t size;/* [value(strlen_m(string))] */
	const char *string;/* [charset(UTF8)] */
};

struct ForestTrustDataDomainInfo {
	uint32_t sid_size;/* [value(ndr_size_dom_sid0(&sid,ndr->flags))] */
	struct dom_sid sid;/* [subcontext(0),subcontext_size(sid_size)] */
	struct ForestTrustString dns_name;
	struct ForestTrustString netbios_name;
}/* [flag(LIBNDR_FLAG_NOALIGN)] */;

struct ForestTrustDataBinaryData {
	uint32_t size;
	uint8_t *data;
}/* [flag(LIBNDR_FLAG_NOALIGN)] */;

union ForestTrustData {
	struct ForestTrustString name;/* [case(FOREST_TRUST_TOP_LEVEL_NAME)] */
	struct ForestTrustDataDomainInfo info;/* [case(FOREST_TRUST_DOMAIN_INFO)] */
	struct ForestTrustDataBinaryData data;/* [default] */
}/* [nodiscriminant] */;

enum ForestTrustInfoRecordType
#ifndef USE_UINT_ENUMS
 {
	FOREST_TRUST_TOP_LEVEL_NAME=(int)(0),
	FOREST_TRUST_TOP_LEVEL_NAME_EX=(int)(1),
	FOREST_TRUST_DOMAIN_INFO=(int)(2)
}
#else
 { __do_not_use_enum_ForestTrustInfoRecordType=0x7FFFFFFF}
#define FOREST_TRUST_TOP_LEVEL_NAME ( 0 )
#define FOREST_TRUST_TOP_LEVEL_NAME_EX ( 1 )
#define FOREST_TRUST_DOMAIN_INFO ( 2 )
#endif
;

struct ForestTrustInfoRecord {
	uint32_t flags;
	NTTIME timestamp;
	enum ForestTrustInfoRecordType type;
	union ForestTrustData data;/* [switch_is(type)] */
}/* [public,gensize,flag(LIBNDR_FLAG_NOALIGN)] */;

struct ForestTrustInfoRecordArmor {
	uint32_t record_size;/* [value(ndr_size_ForestTrustInfoRecord(&record,ndr->flags))] */
	struct ForestTrustInfoRecord record;
}/* [flag(LIBNDR_FLAG_NOALIGN)] */;

struct ForestTrustInfo {
	uint32_t version;
	uint32_t count;
	struct ForestTrustInfoRecordArmor *records;
}/* [flag(LIBNDR_FLAG_NOALIGN),public] */;


struct decode_replPropertyMetaData {
	struct {
		struct replPropertyMetaDataBlob blob;
	} in;

};


struct decode_replUpToDateVector {
	struct {
		struct replUpToDateVectorBlob blob;
	} in;

};


struct decode_repsFromTo {
	struct {
		struct repsFromToBlob blob;
	} in;

};


struct decode_partialAttributeSet {
	struct {
		struct partialAttributeSetBlob blob;
	} in;

};


struct decode_prefixMap {
	struct {
		struct prefixMapBlob blob;
	} in;

};


struct decode_ldapControlDirSync {
	struct {
		struct ldapControlDirSyncCookie cookie;
	} in;

};


struct decode_supplementalCredentials {
	struct {
		struct supplementalCredentialsBlob blob;
	} in;

};


struct decode_Packages {
	struct {
		struct package_PackagesBlob blob;
	} in;

};


struct decode_PrimaryKerberos {
	struct {
		struct package_PrimaryKerberosBlob blob;
	} in;

};


struct decode_PrimaryCLEARTEXT {
	struct {
		struct package_PrimaryCLEARTEXTBlob blob;
	} in;

};


struct decode_PrimaryWDigest {
	struct {
		struct package_PrimaryWDigestBlob blob;
	} in;

};


struct decode_trustAuthInOut {
	struct {
		struct trustAuthInOutBlob blob;
	} in;

};


struct decode_trustDomainPasswords {
	struct {
		struct trustDomainPasswords blob;
	} in;

};


struct decode_ExtendedErrorInfo {
	struct {
		struct ExtendedErrorInfoPtr ptr;/* [subcontext(0xFFFFFC01)] */
	} in;

};


struct decode_ForestTrustInfo {
	struct {
		struct ForestTrustInfo blob;
	} in;

};

#endif /* _HEADER_drsblobs */
#endif /* _PIDL_HEADER_drsblobs */
