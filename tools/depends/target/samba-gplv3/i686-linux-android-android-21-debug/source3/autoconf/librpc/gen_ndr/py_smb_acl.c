
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "autoconf/librpc/gen_ndr/ndr_smb_acl.h"
#include "autoconf/librpc/gen_ndr/ndr_smb_acl_c.h"

staticforward PyTypeObject smb_acl_user_Type;
staticforward PyTypeObject smb_acl_group_Type;
staticforward PyTypeObject smb_acl_entry_Type;
staticforward PyTypeObject smb_acl_t_Type;
staticforward PyTypeObject smb_acl_wrapper_Type;

void initsmb_acl(void);static PyTypeObject *Object_Type;

static PyObject *py_smb_acl_user_get_uid(PyObject *obj, void *closure)
{
	struct smb_acl_user *object = (struct smb_acl_user *)pytalloc_get_ptr(obj);
	PyObject *py_uid;
	py_uid = PyInt_FromLong(object->uid);
	return py_uid;
}

static int py_smb_acl_user_set_uid(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_user *object = (struct smb_acl_user *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->uid = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_smb_acl_user_getsetters[] = {
	{ discard_const_p(char, "uid"), py_smb_acl_user_get_uid, py_smb_acl_user_set_uid },
	{ NULL }
};

static PyObject *py_smb_acl_user_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct smb_acl_user, type);
}


static PyTypeObject smb_acl_user_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "smb_acl.user",
	.tp_getset = py_smb_acl_user_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_smb_acl_user_new,
};


static PyObject *py_smb_acl_group_get_gid(PyObject *obj, void *closure)
{
	struct smb_acl_group *object = (struct smb_acl_group *)pytalloc_get_ptr(obj);
	PyObject *py_gid;
	py_gid = PyInt_FromLong(object->gid);
	return py_gid;
}

static int py_smb_acl_group_set_gid(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_group *object = (struct smb_acl_group *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->gid = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_smb_acl_group_getsetters[] = {
	{ discard_const_p(char, "gid"), py_smb_acl_group_get_gid, py_smb_acl_group_set_gid },
	{ NULL }
};

static PyObject *py_smb_acl_group_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct smb_acl_group, type);
}


static PyTypeObject smb_acl_group_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "smb_acl.group",
	.tp_getset = py_smb_acl_group_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_smb_acl_group_new,
};

PyObject *py_import_smb_acl_entry_info(TALLOC_CTX *mem_ctx, int level, union smb_acl_entry_info *in)
{
	PyObject *ret;

	switch (level) {
		case SMB_ACL_USER:
			ret = pytalloc_reference_ex(&smb_acl_user_Type, mem_ctx, &in->user);
			return ret;

		case SMB_ACL_USER_OBJ:
			ret = Py_None;
			Py_INCREF(ret);
			return ret;

		case SMB_ACL_GROUP:
			ret = pytalloc_reference_ex(&smb_acl_group_Type, mem_ctx, &in->group);
			return ret;

		case SMB_ACL_GROUP_OBJ:
			ret = Py_None;
			Py_INCREF(ret);
			return ret;

		case SMB_ACL_OTHER:
			ret = Py_None;
			Py_INCREF(ret);
			return ret;

		case SMB_ACL_MASK:
			ret = Py_None;
			Py_INCREF(ret);
			return ret;

	}
	PyErr_SetString(PyExc_TypeError, "unknown union level");
	return NULL;
}

union smb_acl_entry_info *py_export_smb_acl_entry_info(TALLOC_CTX *mem_ctx, int level, PyObject *in)
{
	union smb_acl_entry_info *ret = talloc_zero(mem_ctx, union smb_acl_entry_info);
	switch (level) {
		case SMB_ACL_USER:
			PY_CHECK_TYPE(&smb_acl_user_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->user = *(struct smb_acl_user *)pytalloc_get_ptr(in);
			break;

		case SMB_ACL_USER_OBJ:
			break;

		case SMB_ACL_GROUP:
			PY_CHECK_TYPE(&smb_acl_group_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->group = *(struct smb_acl_group *)pytalloc_get_ptr(in);
			break;

		case SMB_ACL_GROUP_OBJ:
			break;

		case SMB_ACL_OTHER:
			break;

		case SMB_ACL_MASK:
			break;

		default:
			PyErr_SetString(PyExc_TypeError, "invalid union level value");
			talloc_free(ret);
			ret = NULL;
	}

	return ret;
}


static PyObject *py_smb_acl_entry_get_a_type(PyObject *obj, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(obj);
	PyObject *py_a_type;
	py_a_type = PyInt_FromLong(object->a_type);
	return py_a_type;
}

static int py_smb_acl_entry_set_a_type(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->a_type = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->a_type = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyObject *py_smb_acl_entry_get_info(PyObject *obj, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(obj);
	PyObject *py_info;
	py_info = py_import_smb_acl_entry_info(pytalloc_get_mem_ctx(obj), object->a_type, &object->info);
	if (py_info == NULL) {
		return NULL;
	}
	return py_info;
}

static int py_smb_acl_entry_set_info(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(py_obj);
	{
		union smb_acl_entry_info *info_switch_0;
		info_switch_0 = py_export_smb_acl_entry_info(pytalloc_get_mem_ctx(py_obj), object->a_type, value);
		if (info_switch_0 == NULL) {
			return -1;
		}
		object->info = *info_switch_0;
	}
	return 0;
}

static PyObject *py_smb_acl_entry_get_a_perm(PyObject *obj, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(obj);
	PyObject *py_a_perm;
	py_a_perm = PyInt_FromLong(object->a_perm);
	return py_a_perm;
}

static int py_smb_acl_entry_set_a_perm(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_entry *object = (struct smb_acl_entry *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->a_perm = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_smb_acl_entry_getsetters[] = {
	{ discard_const_p(char, "a_type"), py_smb_acl_entry_get_a_type, py_smb_acl_entry_set_a_type },
	{ discard_const_p(char, "info"), py_smb_acl_entry_get_info, py_smb_acl_entry_set_info },
	{ discard_const_p(char, "a_perm"), py_smb_acl_entry_get_a_perm, py_smb_acl_entry_set_a_perm },
	{ NULL }
};

static PyObject *py_smb_acl_entry_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct smb_acl_entry, type);
}


static PyTypeObject smb_acl_entry_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "smb_acl.entry",
	.tp_getset = py_smb_acl_entry_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_smb_acl_entry_new,
};


static PyObject *py_smb_acl_t_get_count(PyObject *obj, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(obj);
	PyObject *py_count;
	py_count = PyInt_FromLong(object->count);
	return py_count;
}

static int py_smb_acl_t_set_count(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->count = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_smb_acl_t_get_next(PyObject *obj, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(obj);
	PyObject *py_next;
	py_next = PyInt_FromLong(object->next);
	return py_next;
}

static int py_smb_acl_t_set_next(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->next = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_smb_acl_t_get_acl(PyObject *obj, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(obj);
	PyObject *py_acl;
	py_acl = PyList_New(object->count);
	if (py_acl == NULL) {
		return NULL;
	}
	{
		int acl_cntr_0;
		for (acl_cntr_0 = 0; acl_cntr_0 < object->count; acl_cntr_0++) {
			PyObject *py_acl_0;
			py_acl_0 = pytalloc_reference_ex(&smb_acl_entry_Type, object->acl, &object->acl[acl_cntr_0]);
			PyList_SetItem(py_acl, acl_cntr_0, py_acl_0);
		}
	}
	return py_acl;
}

static int py_smb_acl_t_set_acl(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_t *object = (struct smb_acl_t *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyList_Type, value, return -1;);
	{
		int acl_cntr_0;
		object->acl = talloc_array_ptrtype(pytalloc_get_mem_ctx(py_obj), object->acl, PyList_GET_SIZE(value));
		if (!object->acl) { return -1;; }
		talloc_set_name_const(object->acl, "ARRAY: object->acl");
		for (acl_cntr_0 = 0; acl_cntr_0 < PyList_GET_SIZE(value); acl_cntr_0++) {
			PY_CHECK_TYPE(&smb_acl_entry_Type, PyList_GET_ITEM(value, acl_cntr_0), return -1;);
			if (talloc_reference(object->acl, pytalloc_get_mem_ctx(PyList_GET_ITEM(value, acl_cntr_0))) == NULL) {
				PyErr_NoMemory();
				return -1;
			}
			object->acl[acl_cntr_0] = *(struct smb_acl_entry *)pytalloc_get_ptr(PyList_GET_ITEM(value, acl_cntr_0));
		}
	}
	return 0;
}

static PyGetSetDef py_smb_acl_t_getsetters[] = {
	{ discard_const_p(char, "count"), py_smb_acl_t_get_count, py_smb_acl_t_set_count },
	{ discard_const_p(char, "next"), py_smb_acl_t_get_next, py_smb_acl_t_set_next },
	{ discard_const_p(char, "acl"), py_smb_acl_t_get_acl, py_smb_acl_t_set_acl },
	{ NULL }
};

static PyObject *py_smb_acl_t_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct smb_acl_t, type);
}


static PyTypeObject smb_acl_t_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "smb_acl.t",
	.tp_getset = py_smb_acl_t_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_smb_acl_t_new,
};


static PyObject *py_smb_acl_wrapper_get_access_acl(PyObject *obj, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(obj);
	PyObject *py_access_acl;
	if (object->access_acl == NULL) {
		py_access_acl = Py_None;
		Py_INCREF(py_access_acl);
	} else {
		py_access_acl = pytalloc_reference_ex(&smb_acl_t_Type, object->access_acl, object->access_acl);
	}
	return py_access_acl;
}

static int py_smb_acl_wrapper_set_access_acl(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(py_obj);
	talloc_unlink(pytalloc_get_mem_ctx(py_obj), object->access_acl);
	if (value == Py_None) {
		object->access_acl = NULL;
	} else {
		object->access_acl = NULL;
		PY_CHECK_TYPE(&smb_acl_t_Type, value, return -1;);
		if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->access_acl = (struct smb_acl_t *)pytalloc_get_ptr(value);
	}
	return 0;
}

static PyObject *py_smb_acl_wrapper_get_default_acl(PyObject *obj, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(obj);
	PyObject *py_default_acl;
	if (object->default_acl == NULL) {
		py_default_acl = Py_None;
		Py_INCREF(py_default_acl);
	} else {
		py_default_acl = pytalloc_reference_ex(&smb_acl_t_Type, object->default_acl, object->default_acl);
	}
	return py_default_acl;
}

static int py_smb_acl_wrapper_set_default_acl(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(py_obj);
	talloc_unlink(pytalloc_get_mem_ctx(py_obj), object->default_acl);
	if (value == Py_None) {
		object->default_acl = NULL;
	} else {
		object->default_acl = NULL;
		PY_CHECK_TYPE(&smb_acl_t_Type, value, return -1;);
		if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->default_acl = (struct smb_acl_t *)pytalloc_get_ptr(value);
	}
	return 0;
}

static PyObject *py_smb_acl_wrapper_get_owner(PyObject *obj, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(obj);
	PyObject *py_owner;
	py_owner = PyInt_FromLong(object->owner);
	return py_owner;
}

static int py_smb_acl_wrapper_set_owner(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->owner = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_smb_acl_wrapper_get_group(PyObject *obj, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(obj);
	PyObject *py_group;
	py_group = PyInt_FromLong(object->group);
	return py_group;
}

static int py_smb_acl_wrapper_set_group(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->group = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_smb_acl_wrapper_get_mode(PyObject *obj, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(obj);
	PyObject *py_mode;
	py_mode = PyInt_FromLong(object->mode);
	return py_mode;
}

static int py_smb_acl_wrapper_set_mode(PyObject *py_obj, PyObject *value, void *closure)
{
	struct smb_acl_wrapper *object = (struct smb_acl_wrapper *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->mode = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_smb_acl_wrapper_getsetters[] = {
	{ discard_const_p(char, "access_acl"), py_smb_acl_wrapper_get_access_acl, py_smb_acl_wrapper_set_access_acl },
	{ discard_const_p(char, "default_acl"), py_smb_acl_wrapper_get_default_acl, py_smb_acl_wrapper_set_default_acl },
	{ discard_const_p(char, "owner"), py_smb_acl_wrapper_get_owner, py_smb_acl_wrapper_set_owner },
	{ discard_const_p(char, "group"), py_smb_acl_wrapper_get_group, py_smb_acl_wrapper_set_group },
	{ discard_const_p(char, "mode"), py_smb_acl_wrapper_get_mode, py_smb_acl_wrapper_set_mode },
	{ NULL }
};

static PyObject *py_smb_acl_wrapper_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct smb_acl_wrapper, type);
}


static PyTypeObject smb_acl_wrapper_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "smb_acl.wrapper",
	.tp_getset = py_smb_acl_wrapper_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_smb_acl_wrapper_new,
};

static PyMethodDef smb_acl_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initsmb_acl(void)
{
	PyObject *m;
	PyObject *dep_talloc;

	dep_talloc = PyImport_ImportModule("talloc");
	if (dep_talloc == NULL)
		return;

	Object_Type = (PyTypeObject *)PyObject_GetAttrString(dep_talloc, "Object");
	if (Object_Type == NULL)
		return;

	smb_acl_user_Type.tp_base = Object_Type;

	smb_acl_group_Type.tp_base = Object_Type;

	smb_acl_entry_Type.tp_base = Object_Type;

	smb_acl_t_Type.tp_base = Object_Type;

	smb_acl_wrapper_Type.tp_base = Object_Type;

	if (PyType_Ready(&smb_acl_user_Type) < 0)
		return;
	if (PyType_Ready(&smb_acl_group_Type) < 0)
		return;
	if (PyType_Ready(&smb_acl_entry_Type) < 0)
		return;
	if (PyType_Ready(&smb_acl_t_Type) < 0)
		return;
	if (PyType_Ready(&smb_acl_wrapper_Type) < 0)
		return;
#ifdef PY_USER_PATCH
	PY_USER_PATCH(&smb_acl_user_Type);
#endif
#ifdef PY_GROUP_PATCH
	PY_GROUP_PATCH(&smb_acl_group_Type);
#endif
#ifdef PY_ENTRY_PATCH
	PY_ENTRY_PATCH(&smb_acl_entry_Type);
#endif
#ifdef PY_T_PATCH
	PY_T_PATCH(&smb_acl_t_Type);
#endif
#ifdef PY_WRAPPER_PATCH
	PY_WRAPPER_PATCH(&smb_acl_wrapper_Type);
#endif

	m = Py_InitModule3("smb_acl", smb_acl_methods, "smb_acl DCE/RPC");
	if (m == NULL)
		return;

	PyModule_AddObject(m, "SMB_ACL_NEXT_ENTRY", PyInt_FromLong(1));
	PyModule_AddObject(m, "SMB_ACL_MASK", PyInt_FromLong(SMB_ACL_MASK));
	PyModule_AddObject(m, "SMB_ACL_USER_OBJ", PyInt_FromLong(SMB_ACL_USER_OBJ));
	PyModule_AddObject(m, "SMB_ACL_USER", PyInt_FromLong(SMB_ACL_USER));
	PyModule_AddObject(m, "SMB_ACL_READ", PyInt_FromLong(4));
	PyModule_AddObject(m, "SMB_ACL_WRITE", PyInt_FromLong(2));
	PyModule_AddObject(m, "SMB_ACL_TYPE_ACCESS", PyInt_FromLong(0));
	PyModule_AddObject(m, "SMB_ACL_FIRST_ENTRY", PyInt_FromLong(0));
	PyModule_AddObject(m, "SMB_ACL_GROUP", PyInt_FromLong(SMB_ACL_GROUP));
	PyModule_AddObject(m, "SMB_ACL_TAG_INVALID", PyInt_FromLong(SMB_ACL_TAG_INVALID));
	PyModule_AddObject(m, "SMB_ACL_EXECUTE", PyInt_FromLong(1));
	PyModule_AddObject(m, "SMB_ACL_OTHER", PyInt_FromLong(SMB_ACL_OTHER));
	PyModule_AddObject(m, "SMB_ACL_GROUP_OBJ", PyInt_FromLong(SMB_ACL_GROUP_OBJ));
	PyModule_AddObject(m, "SMB_ACL_TYPE_DEFAULT", PyInt_FromLong(1));
	Py_INCREF((PyObject *)(void *)&smb_acl_user_Type);
	PyModule_AddObject(m, "user", (PyObject *)(void *)&smb_acl_user_Type);
	Py_INCREF((PyObject *)(void *)&smb_acl_group_Type);
	PyModule_AddObject(m, "group", (PyObject *)(void *)&smb_acl_group_Type);
	Py_INCREF((PyObject *)(void *)&smb_acl_entry_Type);
	PyModule_AddObject(m, "entry", (PyObject *)(void *)&smb_acl_entry_Type);
	Py_INCREF((PyObject *)(void *)&smb_acl_t_Type);
	PyModule_AddObject(m, "t", (PyObject *)(void *)&smb_acl_t_Type);
	Py_INCREF((PyObject *)(void *)&smb_acl_wrapper_Type);
	PyModule_AddObject(m, "wrapper", (PyObject *)(void *)&smb_acl_wrapper_Type);
#ifdef PY_MOD_SMB_ACL_PATCH
	PY_MOD_SMB_ACL_PATCH(m);
#endif

}
