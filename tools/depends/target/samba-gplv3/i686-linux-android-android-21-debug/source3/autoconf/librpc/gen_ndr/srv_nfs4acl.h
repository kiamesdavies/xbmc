#include "autoconf/librpc/gen_ndr/ndr_nfs4acl.h"
#ifndef __SRV_NFS4ACL__
#define __SRV_NFS4ACL__
NTSTATUS _nfs4acl_test(struct pipes_struct *p, struct nfs4acl_test *r);
void nfs4acl_get_pipe_fns(struct api_struct **fns, int *n_fns);
struct rpc_srv_callbacks;
NTSTATUS rpc_nfs4acl_init(const struct rpc_srv_callbacks *rpc_srv_cb);
NTSTATUS rpc_nfs4acl_shutdown(void);
#endif /* __SRV_NFS4ACL__ */
