/*
 * Unix SMB/CIFS implementation.
 * server auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "ntdomain.h"
#include "autoconf/librpc/gen_ndr/srv_orpc.h"


/* Tables */
static struct api_struct api_ObjectRpcBaseTypes_cmds[] = 
{
};

void ObjectRpcBaseTypes_get_pipe_fns(struct api_struct **fns, int *n_fns)
{
	*fns = api_ObjectRpcBaseTypes_cmds;
	*n_fns = sizeof(api_ObjectRpcBaseTypes_cmds) / sizeof(struct api_struct);
}

NTSTATUS rpc_ObjectRpcBaseTypes_init(const struct rpc_srv_callbacks *rpc_srv_cb)
{
	return rpc_srv_register(SMB_RPC_INTERFACE_VERSION, "ObjectRpcBaseTypes", "ObjectRpcBaseTypes", &ndr_table_ObjectRpcBaseTypes, api_ObjectRpcBaseTypes_cmds, sizeof(api_ObjectRpcBaseTypes_cmds) / sizeof(struct api_struct), rpc_srv_cb);
}

NTSTATUS rpc_ObjectRpcBaseTypes_shutdown(void)
{
	return rpc_srv_unregister(&ndr_table_ObjectRpcBaseTypes);
}
