/*
 * Unix SMB/CIFS implementation.
 * server auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "ntdomain.h"
#include "autoconf/librpc/gen_ndr/srv_unixinfo.h"

static bool api_unixinfo_SidToUid(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct unixinfo_SidToUid *r;

	call = &ndr_table_unixinfo.calls[NDR_UNIXINFO_SIDTOUID];

	r = talloc(talloc_tos(), struct unixinfo_SidToUid);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_SidToUid, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.uid = talloc_zero(r, uint64_t);
	if (r->out.uid == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _unixinfo_SidToUid(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_SidToUid, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_unixinfo_UidToSid(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct unixinfo_UidToSid *r;

	call = &ndr_table_unixinfo.calls[NDR_UNIXINFO_UIDTOSID];

	r = talloc(talloc_tos(), struct unixinfo_UidToSid);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_UidToSid, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.sid = talloc_zero(r, struct dom_sid);
	if (r->out.sid == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _unixinfo_UidToSid(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_UidToSid, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_unixinfo_SidToGid(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct unixinfo_SidToGid *r;

	call = &ndr_table_unixinfo.calls[NDR_UNIXINFO_SIDTOGID];

	r = talloc(talloc_tos(), struct unixinfo_SidToGid);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_SidToGid, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.gid = talloc_zero(r, uint64_t);
	if (r->out.gid == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _unixinfo_SidToGid(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_SidToGid, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_unixinfo_GidToSid(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct unixinfo_GidToSid *r;

	call = &ndr_table_unixinfo.calls[NDR_UNIXINFO_GIDTOSID];

	r = talloc(talloc_tos(), struct unixinfo_GidToSid);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_GidToSid, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.sid = talloc_zero(r, struct dom_sid);
	if (r->out.sid == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _unixinfo_GidToSid(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_GidToSid, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_unixinfo_GetPWUid(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct unixinfo_GetPWUid *r;

	call = &ndr_table_unixinfo.calls[NDR_UNIXINFO_GETPWUID];

	r = talloc(talloc_tos(), struct unixinfo_GetPWUid);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_GetPWUid, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.count = r->in.count;
	r->out.infos = talloc_zero_array(r, struct unixinfo_GetPWUidInfo, *r->out.count);
	if (r->out.infos == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _unixinfo_GetPWUid(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(unixinfo_GetPWUid, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}


/* Tables */
static struct api_struct api_unixinfo_cmds[] = 
{
	{"UNIXINFO_SIDTOUID", NDR_UNIXINFO_SIDTOUID, api_unixinfo_SidToUid},
	{"UNIXINFO_UIDTOSID", NDR_UNIXINFO_UIDTOSID, api_unixinfo_UidToSid},
	{"UNIXINFO_SIDTOGID", NDR_UNIXINFO_SIDTOGID, api_unixinfo_SidToGid},
	{"UNIXINFO_GIDTOSID", NDR_UNIXINFO_GIDTOSID, api_unixinfo_GidToSid},
	{"UNIXINFO_GETPWUID", NDR_UNIXINFO_GETPWUID, api_unixinfo_GetPWUid},
};

void unixinfo_get_pipe_fns(struct api_struct **fns, int *n_fns)
{
	*fns = api_unixinfo_cmds;
	*n_fns = sizeof(api_unixinfo_cmds) / sizeof(struct api_struct);
}

NTSTATUS rpc_unixinfo_init(const struct rpc_srv_callbacks *rpc_srv_cb)
{
	return rpc_srv_register(SMB_RPC_INTERFACE_VERSION, "unixinfo", "unixinfo", &ndr_table_unixinfo, api_unixinfo_cmds, sizeof(api_unixinfo_cmds) / sizeof(struct api_struct), rpc_srv_cb);
}

NTSTATUS rpc_unixinfo_shutdown(void)
{
	return rpc_srv_unregister(&ndr_table_unixinfo);
}
