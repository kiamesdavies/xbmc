/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_open_files
#define _PIDL_HEADER_open_files

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/server_id.h"
#include "librpc/gen_ndr/security.h"
#include "librpc/gen_ndr/file_id.h"
#ifndef _HEADER_open_files
#define _HEADER_open_files

#define VFS_DEFAULT_DURABLE_COOKIE_MAGIC	( "VFS_DEFAULT_DURABLE_COOKIE_MAGIC                " )
#define VFS_DEFAULT_DURABLE_COOKIE_VERSION	( 0 )
struct share_mode_entry {
	struct server_id pid;
	uint64_t op_mid;
	uint16_t op_type;
	uint32_t access_mask;
	uint32_t share_access;
	uint32_t private_options;
	struct timeval time;
	struct file_id id;
	uint64_t share_file_id;
	uint32_t uid;
	uint16_t flags;
	uint32_t name_hash;
	uint8_t stale;/* [skip] */
}/* [public] */;

struct delete_token {
	uint32_t name_hash;
	struct security_token *delete_nt_token;/* [unique] */
	struct security_unix_token *delete_token;/* [unique] */
}/* [public] */;

struct share_mode_data {
	const char *servicepath;/* [unique,charset(UTF8)] */
	const char *base_name;/* [unique,charset(UTF8)] */
	const char *stream_name;/* [charset(UTF8),unique] */
	struct file_id id;
	uint32_t num_share_modes;
	struct share_mode_entry *share_modes;/* [size_is(num_share_modes)] */
	uint32_t num_delete_tokens;
	struct delete_token *delete_tokens;/* [size_is(num_delete_tokens)] */
	struct timespec old_write_time;
	struct timespec changed_write_time;
	uint8_t fresh;/* [skip] */
	uint8_t modified;/* [skip] */
	struct db_record *record;/* [ignore] */
}/* [public] */;

struct vfs_default_durable_stat {
	uint64_t st_ex_dev;
	uint64_t st_ex_ino;
	uint64_t st_ex_mode;
	uint64_t st_ex_nlink;
	uint64_t st_ex_uid;
	uint64_t st_ex_gid;
	uint64_t st_ex_rdev;
	uint64_t st_ex_size;
	struct timespec st_ex_atime;
	struct timespec st_ex_mtime;
	struct timespec st_ex_ctime;
	struct timespec st_ex_btime;
	uint8_t st_ex_calculated_birthtime;
	uint64_t st_ex_blksize;
	uint64_t st_ex_blocks;
	uint32_t st_ex_flags;
	uint32_t st_ex_mask;
};

struct vfs_default_durable_cookie {
	const char *magic;/* [value(VFS_DEFAULT_DURABLE_COOKIE_MAGIC),charset(DOS)] */
	uint32_t version;/* [value(VFS_DEFAULT_DURABLE_COOKIE_VERSION)] */
	uint8_t allow_reconnect;
	struct file_id id;
	const char *servicepath;/* [unique,charset(UTF8)] */
	const char *base_name;/* [charset(UTF8),unique] */
	uint64_t initial_allocation_size;
	uint64_t position_information;
	uint8_t update_write_time_triggered;
	uint8_t update_write_time_on_close;
	uint8_t write_time_forced;
	struct timespec close_write_time;
	struct vfs_default_durable_stat stat_info;
}/* [public] */;

#endif /* _HEADER_open_files */
#endif /* _PIDL_HEADER_open_files */
