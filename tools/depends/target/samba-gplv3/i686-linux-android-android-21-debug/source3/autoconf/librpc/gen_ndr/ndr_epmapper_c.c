/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "autoconf/librpc/gen_ndr/ndr_epmapper.h"
#include "autoconf/librpc/gen_ndr/ndr_epmapper_c.h"

/* epmapper - client functions generated by pidl */

struct dcerpc_epm_Insert_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Insert_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Insert_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_Insert *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_Insert_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Insert_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_INSERT, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Insert_r_done, req);

	return req;
}

static void dcerpc_epm_Insert_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Insert_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_Insert_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_Insert_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Insert_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_Insert *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_INSERT, mem_ctx, r);

	return status;
}

struct dcerpc_epm_Insert_state {
	struct epm_Insert orig;
	struct epm_Insert tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Insert_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Insert_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct dcerpc_binding_handle *h,
					  uint32_t _num_ents /* [in]  */,
					  struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */,
					  uint32_t _replace /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_epm_Insert_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Insert_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.num_ents = _num_ents;
	state->orig.in.entries = _entries;
	state->orig.in.replace = _replace;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_Insert_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Insert_done, req);
	return req;
}

static void dcerpc_epm_Insert_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_Insert_state *state = tevent_req_data(
		req, struct dcerpc_epm_Insert_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_Insert_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Insert_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32_t *result)
{
	struct dcerpc_epm_Insert_state *state = tevent_req_data(
		req, struct dcerpc_epm_Insert_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Insert(struct dcerpc_binding_handle *h,
			   TALLOC_CTX *mem_ctx,
			   uint32_t _num_ents /* [in]  */,
			   struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */,
			   uint32_t _replace /* [in]  */,
			   uint32_t *result)
{
	struct epm_Insert r;
	NTSTATUS status;

	/* In parameters */
	r.in.num_ents = _num_ents;
	r.in.entries = _entries;
	r.in.replace = _replace;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_Insert_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_Delete_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Delete_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Delete_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_Delete *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_Delete_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Delete_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_DELETE, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Delete_r_done, req);

	return req;
}

static void dcerpc_epm_Delete_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Delete_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_Delete_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_Delete_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Delete_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_Delete *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_DELETE, mem_ctx, r);

	return status;
}

struct dcerpc_epm_Delete_state {
	struct epm_Delete orig;
	struct epm_Delete tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Delete_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Delete_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct dcerpc_binding_handle *h,
					  uint32_t _num_ents /* [in]  */,
					  struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_Delete_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Delete_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.num_ents = _num_ents;
	state->orig.in.entries = _entries;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_Delete_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Delete_done, req);
	return req;
}

static void dcerpc_epm_Delete_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_Delete_state *state = tevent_req_data(
		req, struct dcerpc_epm_Delete_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_Delete_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Delete_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32_t *result)
{
	struct dcerpc_epm_Delete_state *state = tevent_req_data(
		req, struct dcerpc_epm_Delete_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Delete(struct dcerpc_binding_handle *h,
			   TALLOC_CTX *mem_ctx,
			   uint32_t _num_ents /* [in]  */,
			   struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */,
			   uint32_t *result)
{
	struct epm_Delete r;
	NTSTATUS status;

	/* In parameters */
	r.in.num_ents = _num_ents;
	r.in.entries = _entries;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_Delete_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_Lookup_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Lookup_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Lookup_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_Lookup *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_Lookup_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Lookup_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_LOOKUP, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Lookup_r_done, req);

	return req;
}

static void dcerpc_epm_Lookup_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Lookup_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_Lookup_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_Lookup_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Lookup_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_Lookup *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_LOOKUP, mem_ctx, r);

	return status;
}

struct dcerpc_epm_Lookup_state {
	struct epm_Lookup orig;
	struct epm_Lookup tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Lookup_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Lookup_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct dcerpc_binding_handle *h,
					  enum epm_InquiryType _inquiry_type /* [in]  */,
					  struct GUID *_object /* [in] [ptr] */,
					  struct rpc_if_id_t *_interface_id /* [in] [ptr] */,
					  enum epm_VersionOption _vers_option /* [in]  */,
					  struct policy_handle *_entry_handle /* [in,out] [ref] */,
					  uint32_t _max_ents /* [in]  */,
					  uint32_t *_num_ents /* [out] [ref] */,
					  struct epm_entry_t *_entries /* [out] [size_is(max_ents),length_is(*num_ents)] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_Lookup_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Lookup_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.inquiry_type = _inquiry_type;
	state->orig.in.object = _object;
	state->orig.in.interface_id = _interface_id;
	state->orig.in.vers_option = _vers_option;
	state->orig.in.entry_handle = _entry_handle;
	state->orig.in.max_ents = _max_ents;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;
	state->orig.out.num_ents = _num_ents;
	state->orig.out.entries = _entries;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_epm_Lookup_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_Lookup_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Lookup_done, req);
	return req;
}

static void dcerpc_epm_Lookup_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_Lookup_state *state = tevent_req_data(
		req, struct dcerpc_epm_Lookup_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_Lookup_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;
	*state->orig.out.num_ents = *state->tmp.out.num_ents;
	{
		size_t _copy_len_entries;
		if ((*state->tmp.out.num_ents) > (state->tmp.in.max_ents)) {
			tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
			return;
		}
		_copy_len_entries = *state->tmp.out.num_ents;
		memcpy(state->orig.out.entries, state->tmp.out.entries, _copy_len_entries * sizeof(*state->orig.out.entries));
	}

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Lookup_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32_t *result)
{
	struct dcerpc_epm_Lookup_state *state = tevent_req_data(
		req, struct dcerpc_epm_Lookup_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Lookup(struct dcerpc_binding_handle *h,
			   TALLOC_CTX *mem_ctx,
			   enum epm_InquiryType _inquiry_type /* [in]  */,
			   struct GUID *_object /* [in] [ptr] */,
			   struct rpc_if_id_t *_interface_id /* [in] [ptr] */,
			   enum epm_VersionOption _vers_option /* [in]  */,
			   struct policy_handle *_entry_handle /* [in,out] [ref] */,
			   uint32_t _max_ents /* [in]  */,
			   uint32_t *_num_ents /* [out] [ref] */,
			   struct epm_entry_t *_entries /* [out] [size_is(max_ents),length_is(*num_ents)] */,
			   uint32_t *result)
{
	struct epm_Lookup r;
	NTSTATUS status;

	/* In parameters */
	r.in.inquiry_type = _inquiry_type;
	r.in.object = _object;
	r.in.interface_id = _interface_id;
	r.in.vers_option = _vers_option;
	r.in.entry_handle = _entry_handle;
	r.in.max_ents = _max_ents;

	/* Out parameters */
	r.out.entry_handle = _entry_handle;
	r.out.num_ents = _num_ents;
	r.out.entries = _entries;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_Lookup_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_entry_handle = *r.out.entry_handle;
	*_num_ents = *r.out.num_ents;
	{
		size_t _copy_len_entries;
		if ((*r.out.num_ents) > (r.in.max_ents)) {
			return NT_STATUS_INVALID_NETWORK_RESPONSE;
		}
		_copy_len_entries = *r.out.num_ents;
		memcpy(_entries, r.out.entries, _copy_len_entries * sizeof(*_entries));
	}

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_Map_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Map_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Map_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_Map *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_Map_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Map_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_MAP, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Map_r_done, req);

	return req;
}

static void dcerpc_epm_Map_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Map_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_Map_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_Map_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Map_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_Map *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_MAP, mem_ctx, r);

	return status;
}

struct dcerpc_epm_Map_state {
	struct epm_Map orig;
	struct epm_Map tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_Map_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_Map_send(TALLOC_CTX *mem_ctx,
				       struct tevent_context *ev,
				       struct dcerpc_binding_handle *h,
				       struct GUID *_object /* [in] [ptr] */,
				       struct epm_twr_t *_map_tower /* [in] [ptr] */,
				       struct policy_handle *_entry_handle /* [in,out] [ref] */,
				       uint32_t _max_towers /* [in]  */,
				       uint32_t *_num_towers /* [out] [ref] */,
				       struct epm_twr_p_t *_towers /* [out] [size_is(max_towers),length_is(*num_towers)] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_Map_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_Map_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.object = _object;
	state->orig.in.map_tower = _map_tower;
	state->orig.in.entry_handle = _entry_handle;
	state->orig.in.max_towers = _max_towers;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;
	state->orig.out.num_towers = _num_towers;
	state->orig.out.towers = _towers;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_epm_Map_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_Map_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_Map_done, req);
	return req;
}

static void dcerpc_epm_Map_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_Map_state *state = tevent_req_data(
		req, struct dcerpc_epm_Map_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_Map_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;
	*state->orig.out.num_towers = *state->tmp.out.num_towers;
	{
		size_t _copy_len_towers;
		if ((*state->tmp.out.num_towers) > (state->tmp.in.max_towers)) {
			tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
			return;
		}
		_copy_len_towers = *state->tmp.out.num_towers;
		memcpy(state->orig.out.towers, state->tmp.out.towers, _copy_len_towers * sizeof(*state->orig.out.towers));
	}

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_Map_recv(struct tevent_req *req,
			     TALLOC_CTX *mem_ctx,
			     uint32_t *result)
{
	struct dcerpc_epm_Map_state *state = tevent_req_data(
		req, struct dcerpc_epm_Map_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_Map(struct dcerpc_binding_handle *h,
			TALLOC_CTX *mem_ctx,
			struct GUID *_object /* [in] [ptr] */,
			struct epm_twr_t *_map_tower /* [in] [ptr] */,
			struct policy_handle *_entry_handle /* [in,out] [ref] */,
			uint32_t _max_towers /* [in]  */,
			uint32_t *_num_towers /* [out] [ref] */,
			struct epm_twr_p_t *_towers /* [out] [size_is(max_towers),length_is(*num_towers)] */,
			uint32_t *result)
{
	struct epm_Map r;
	NTSTATUS status;

	/* In parameters */
	r.in.object = _object;
	r.in.map_tower = _map_tower;
	r.in.entry_handle = _entry_handle;
	r.in.max_towers = _max_towers;

	/* Out parameters */
	r.out.entry_handle = _entry_handle;
	r.out.num_towers = _num_towers;
	r.out.towers = _towers;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_Map_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_entry_handle = *r.out.entry_handle;
	*_num_towers = *r.out.num_towers;
	{
		size_t _copy_len_towers;
		if ((*r.out.num_towers) > (r.in.max_towers)) {
			return NT_STATUS_INVALID_NETWORK_RESPONSE;
		}
		_copy_len_towers = *r.out.num_towers;
		memcpy(_towers, r.out.towers, _copy_len_towers * sizeof(*_towers));
	}

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_LookupHandleFree_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_LookupHandleFree_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_LookupHandleFree_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_LookupHandleFree *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_LookupHandleFree_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_LookupHandleFree_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_LOOKUPHANDLEFREE, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_LookupHandleFree_r_done, req);

	return req;
}

static void dcerpc_epm_LookupHandleFree_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_LookupHandleFree_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_LookupHandleFree_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_LookupHandleFree_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_LookupHandleFree_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_LookupHandleFree *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_LOOKUPHANDLEFREE, mem_ctx, r);

	return status;
}

struct dcerpc_epm_LookupHandleFree_state {
	struct epm_LookupHandleFree orig;
	struct epm_LookupHandleFree tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_LookupHandleFree_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_LookupHandleFree_send(TALLOC_CTX *mem_ctx,
						    struct tevent_context *ev,
						    struct dcerpc_binding_handle *h,
						    struct policy_handle *_entry_handle /* [in,out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_LookupHandleFree_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_LookupHandleFree_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.entry_handle = _entry_handle;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_epm_LookupHandleFree_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_LookupHandleFree_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_LookupHandleFree_done, req);
	return req;
}

static void dcerpc_epm_LookupHandleFree_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_LookupHandleFree_state *state = tevent_req_data(
		req, struct dcerpc_epm_LookupHandleFree_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_LookupHandleFree_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_LookupHandleFree_recv(struct tevent_req *req,
					  TALLOC_CTX *mem_ctx,
					  uint32_t *result)
{
	struct dcerpc_epm_LookupHandleFree_state *state = tevent_req_data(
		req, struct dcerpc_epm_LookupHandleFree_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_LookupHandleFree(struct dcerpc_binding_handle *h,
				     TALLOC_CTX *mem_ctx,
				     struct policy_handle *_entry_handle /* [in,out] [ref] */,
				     uint32_t *result)
{
	struct epm_LookupHandleFree r;
	NTSTATUS status;

	/* In parameters */
	r.in.entry_handle = _entry_handle;

	/* Out parameters */
	r.out.entry_handle = _entry_handle;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_LookupHandleFree_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_entry_handle = *r.out.entry_handle;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_InqObject_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_InqObject_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_InqObject_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_InqObject *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_InqObject_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_InqObject_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_INQOBJECT, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_InqObject_r_done, req);

	return req;
}

static void dcerpc_epm_InqObject_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_InqObject_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_InqObject_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_InqObject_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_InqObject_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_InqObject *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_INQOBJECT, mem_ctx, r);

	return status;
}

struct dcerpc_epm_InqObject_state {
	struct epm_InqObject orig;
	struct epm_InqObject tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_InqObject_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_InqObject_send(TALLOC_CTX *mem_ctx,
					     struct tevent_context *ev,
					     struct dcerpc_binding_handle *h,
					     struct GUID *_epm_object /* [in] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_InqObject_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_InqObject_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.epm_object = _epm_object;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_InqObject_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_InqObject_done, req);
	return req;
}

static void dcerpc_epm_InqObject_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_InqObject_state *state = tevent_req_data(
		req, struct dcerpc_epm_InqObject_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_InqObject_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_InqObject_recv(struct tevent_req *req,
				   TALLOC_CTX *mem_ctx,
				   uint32_t *result)
{
	struct dcerpc_epm_InqObject_state *state = tevent_req_data(
		req, struct dcerpc_epm_InqObject_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_InqObject(struct dcerpc_binding_handle *h,
			      TALLOC_CTX *mem_ctx,
			      struct GUID *_epm_object /* [in] [ref] */,
			      uint32_t *result)
{
	struct epm_InqObject r;
	NTSTATUS status;

	/* In parameters */
	r.in.epm_object = _epm_object;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_InqObject_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_epm_MgmtDelete_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_MgmtDelete_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_MgmtDelete_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct epm_MgmtDelete *r)
{
	struct tevent_req *req;
	struct dcerpc_epm_MgmtDelete_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_MgmtDelete_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_MGMTDELETE, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_MgmtDelete_r_done, req);

	return req;
}

static void dcerpc_epm_MgmtDelete_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_MgmtDelete_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_epm_MgmtDelete_r_state *state =
		tevent_req_data(req,
		struct dcerpc_epm_MgmtDelete_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_MgmtDelete_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct epm_MgmtDelete *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_epmapper,
			NDR_EPM_MGMTDELETE, mem_ctx, r);

	return status;
}

struct dcerpc_epm_MgmtDelete_state {
	struct epm_MgmtDelete orig;
	struct epm_MgmtDelete tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_epm_MgmtDelete_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_epm_MgmtDelete_send(TALLOC_CTX *mem_ctx,
					      struct tevent_context *ev,
					      struct dcerpc_binding_handle *h,
					      uint32_t _object_speced /* [in]  */,
					      struct GUID *_object /* [in] [ptr] */,
					      struct epm_twr_t *_tower /* [in] [ptr] */)
{
	struct tevent_req *req;
	struct dcerpc_epm_MgmtDelete_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_epm_MgmtDelete_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.object_speced = _object_speced;
	state->orig.in.object = _object;
	state->orig.in.tower = _tower;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_epm_MgmtDelete_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_epm_MgmtDelete_done, req);
	return req;
}

static void dcerpc_epm_MgmtDelete_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_epm_MgmtDelete_state *state = tevent_req_data(
		req, struct dcerpc_epm_MgmtDelete_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_epm_MgmtDelete_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_epm_MgmtDelete_recv(struct tevent_req *req,
				    TALLOC_CTX *mem_ctx,
				    uint32_t *result)
{
	struct dcerpc_epm_MgmtDelete_state *state = tevent_req_data(
		req, struct dcerpc_epm_MgmtDelete_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_epm_MgmtDelete(struct dcerpc_binding_handle *h,
			       TALLOC_CTX *mem_ctx,
			       uint32_t _object_speced /* [in]  */,
			       struct GUID *_object /* [in] [ptr] */,
			       struct epm_twr_t *_tower /* [in] [ptr] */,
			       uint32_t *result)
{
	struct epm_MgmtDelete r;
	NTSTATUS status;

	/* In parameters */
	r.in.object_speced = _object_speced;
	r.in.object = _object;
	r.in.tower = _tower;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_epm_MgmtDelete_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

