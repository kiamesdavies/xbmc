
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "autoconf/librpc/gen_ndr/ndr_echo.h"
#include "autoconf/librpc/gen_ndr/ndr_echo_c.h"

staticforward PyTypeObject echo_info1_Type;
staticforward PyTypeObject echo_info2_Type;
staticforward PyTypeObject echo_info3_Type;
staticforward PyTypeObject echo_info4_Type;
staticforward PyTypeObject echo_info5_Type;
staticforward PyTypeObject echo_info6_Type;
staticforward PyTypeObject echo_info7_Type;
staticforward PyTypeObject echo_Enum2_Type;
staticforward PyTypeObject echo_Surrounding_Type;
staticforward PyTypeObject rpcecho_InterfaceType;

void initecho(void);static PyTypeObject *ClientConnection_Type;
static PyTypeObject *Object_Type;

static PyObject *py_echo_info1_get_v(PyObject *obj, void *closure)
{
	struct echo_info1 *object = (struct echo_info1 *)pytalloc_get_ptr(obj);
	PyObject *py_v;
	py_v = PyInt_FromLong(object->v);
	return py_v;
}

static int py_echo_info1_set_v(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info1 *object = (struct echo_info1 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_echo_info1_getsetters[] = {
	{ discard_const_p(char, "v"), py_echo_info1_get_v, py_echo_info1_set_v },
	{ NULL }
};

static PyObject *py_echo_info1_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info1, type);
}

static PyObject *py_echo_info1_ndr_pack(PyObject *py_obj)
{
	struct echo_info1 *object = (struct echo_info1 *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	enum ndr_err_code err;
	err = ndr_push_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_push_flags_fn_t)ndr_push_echo_info1);
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	return PyString_FromStringAndSize((char *)blob.data, blob.length);
}

static PyObject *py_echo_info1_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct echo_info1 *object = (struct echo_info1 *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	int blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_echo_info1);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_echo_info1);
	}
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_echo_info1_ndr_print(PyObject *py_obj)
{
	struct echo_info1 *object = (struct echo_info1 *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_echo_info1, "echo_info1", object);
	ret = PyString_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_echo_info1_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_echo_info1_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", (PyCFunction)py_echo_info1_ndr_unpack, METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_echo_info1_ndr_print, METH_VARARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject echo_info1_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info1",
	.tp_getset = py_echo_info1_getsetters,
	.tp_methods = py_echo_info1_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info1_new,
};


static PyObject *py_echo_info2_get_v(PyObject *obj, void *closure)
{
	struct echo_info2 *object = (struct echo_info2 *)pytalloc_get_ptr(obj);
	PyObject *py_v;
	py_v = PyInt_FromLong(object->v);
	return py_v;
}

static int py_echo_info2_set_v(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info2 *object = (struct echo_info2 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_echo_info2_getsetters[] = {
	{ discard_const_p(char, "v"), py_echo_info2_get_v, py_echo_info2_set_v },
	{ NULL }
};

static PyObject *py_echo_info2_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info2, type);
}


static PyTypeObject echo_info2_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info2",
	.tp_getset = py_echo_info2_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info2_new,
};


static PyObject *py_echo_info3_get_v(PyObject *obj, void *closure)
{
	struct echo_info3 *object = (struct echo_info3 *)pytalloc_get_ptr(obj);
	PyObject *py_v;
	py_v = PyInt_FromLong(object->v);
	return py_v;
}

static int py_echo_info3_set_v(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info3 *object = (struct echo_info3 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v = PyInt_AsLong(value);
	return 0;
}

static PyGetSetDef py_echo_info3_getsetters[] = {
	{ discard_const_p(char, "v"), py_echo_info3_get_v, py_echo_info3_set_v },
	{ NULL }
};

static PyObject *py_echo_info3_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info3, type);
}


static PyTypeObject echo_info3_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info3",
	.tp_getset = py_echo_info3_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info3_new,
};


static PyObject *py_echo_info4_get_v(PyObject *obj, void *closure)
{
	struct echo_info4 *object = (struct echo_info4 *)pytalloc_get_ptr(obj);
	PyObject *py_v;
	py_v = PyLong_FromLongLong(object->v);
	return py_v;
}

static int py_echo_info4_set_v(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info4 *object = (struct echo_info4 *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->v = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->v = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyGetSetDef py_echo_info4_getsetters[] = {
	{ discard_const_p(char, "v"), py_echo_info4_get_v, py_echo_info4_set_v },
	{ NULL }
};

static PyObject *py_echo_info4_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info4, type);
}


static PyTypeObject echo_info4_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info4",
	.tp_getset = py_echo_info4_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info4_new,
};


static PyObject *py_echo_info5_get_v1(PyObject *obj, void *closure)
{
	struct echo_info5 *object = (struct echo_info5 *)pytalloc_get_ptr(obj);
	PyObject *py_v1;
	py_v1 = PyInt_FromLong(object->v1);
	return py_v1;
}

static int py_echo_info5_set_v1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info5 *object = (struct echo_info5 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v1 = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_echo_info5_get_v2(PyObject *obj, void *closure)
{
	struct echo_info5 *object = (struct echo_info5 *)pytalloc_get_ptr(obj);
	PyObject *py_v2;
	py_v2 = PyLong_FromLongLong(object->v2);
	return py_v2;
}

static int py_echo_info5_set_v2(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info5 *object = (struct echo_info5 *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->v2 = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->v2 = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyGetSetDef py_echo_info5_getsetters[] = {
	{ discard_const_p(char, "v1"), py_echo_info5_get_v1, py_echo_info5_set_v1 },
	{ discard_const_p(char, "v2"), py_echo_info5_get_v2, py_echo_info5_set_v2 },
	{ NULL }
};

static PyObject *py_echo_info5_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info5, type);
}


static PyTypeObject echo_info5_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info5",
	.tp_getset = py_echo_info5_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info5_new,
};


static PyObject *py_echo_info6_get_v1(PyObject *obj, void *closure)
{
	struct echo_info6 *object = (struct echo_info6 *)pytalloc_get_ptr(obj);
	PyObject *py_v1;
	py_v1 = PyInt_FromLong(object->v1);
	return py_v1;
}

static int py_echo_info6_set_v1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info6 *object = (struct echo_info6 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v1 = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_echo_info6_get_info1(PyObject *obj, void *closure)
{
	struct echo_info6 *object = (struct echo_info6 *)pytalloc_get_ptr(obj);
	PyObject *py_info1;
	py_info1 = pytalloc_reference_ex(&echo_info1_Type, pytalloc_get_mem_ctx(obj), &object->info1);
	return py_info1;
}

static int py_echo_info6_set_info1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info6 *object = (struct echo_info6 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&echo_info1_Type, value, return -1;);
	if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
		PyErr_NoMemory();
		return -1;
	}
	object->info1 = *(struct echo_info1 *)pytalloc_get_ptr(value);
	return 0;
}

static PyGetSetDef py_echo_info6_getsetters[] = {
	{ discard_const_p(char, "v1"), py_echo_info6_get_v1, py_echo_info6_set_v1 },
	{ discard_const_p(char, "info1"), py_echo_info6_get_info1, py_echo_info6_set_info1 },
	{ NULL }
};

static PyObject *py_echo_info6_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info6, type);
}


static PyTypeObject echo_info6_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info6",
	.tp_getset = py_echo_info6_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info6_new,
};


static PyObject *py_echo_info7_get_v1(PyObject *obj, void *closure)
{
	struct echo_info7 *object = (struct echo_info7 *)pytalloc_get_ptr(obj);
	PyObject *py_v1;
	py_v1 = PyInt_FromLong(object->v1);
	return py_v1;
}

static int py_echo_info7_set_v1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info7 *object = (struct echo_info7 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->v1 = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_echo_info7_get_info4(PyObject *obj, void *closure)
{
	struct echo_info7 *object = (struct echo_info7 *)pytalloc_get_ptr(obj);
	PyObject *py_info4;
	py_info4 = pytalloc_reference_ex(&echo_info4_Type, pytalloc_get_mem_ctx(obj), &object->info4);
	return py_info4;
}

static int py_echo_info7_set_info4(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_info7 *object = (struct echo_info7 *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&echo_info4_Type, value, return -1;);
	if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
		PyErr_NoMemory();
		return -1;
	}
	object->info4 = *(struct echo_info4 *)pytalloc_get_ptr(value);
	return 0;
}

static PyGetSetDef py_echo_info7_getsetters[] = {
	{ discard_const_p(char, "v1"), py_echo_info7_get_v1, py_echo_info7_set_v1 },
	{ discard_const_p(char, "info4"), py_echo_info7_get_info4, py_echo_info7_set_info4 },
	{ NULL }
};

static PyObject *py_echo_info7_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_info7, type);
}


static PyTypeObject echo_info7_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.info7",
	.tp_getset = py_echo_info7_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_info7_new,
};

PyObject *py_import_echo_Info(TALLOC_CTX *mem_ctx, int level, union echo_Info *in)
{
	PyObject *ret;

	switch (level) {
		case 1:
			ret = pytalloc_reference_ex(&echo_info1_Type, mem_ctx, &in->info1);
			return ret;

		case 2:
			ret = pytalloc_reference_ex(&echo_info2_Type, mem_ctx, &in->info2);
			return ret;

		case 3:
			ret = pytalloc_reference_ex(&echo_info3_Type, mem_ctx, &in->info3);
			return ret;

		case 4:
			ret = pytalloc_reference_ex(&echo_info4_Type, mem_ctx, &in->info4);
			return ret;

		case 5:
			ret = pytalloc_reference_ex(&echo_info5_Type, mem_ctx, &in->info5);
			return ret;

		case 6:
			ret = pytalloc_reference_ex(&echo_info6_Type, mem_ctx, &in->info6);
			return ret;

		case 7:
			ret = pytalloc_reference_ex(&echo_info7_Type, mem_ctx, &in->info7);
			return ret;

	}
	PyErr_SetString(PyExc_TypeError, "unknown union level");
	return NULL;
}

union echo_Info *py_export_echo_Info(TALLOC_CTX *mem_ctx, int level, PyObject *in)
{
	union echo_Info *ret = talloc_zero(mem_ctx, union echo_Info);
	switch (level) {
		case 1:
			PY_CHECK_TYPE(&echo_info1_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info1 = *(struct echo_info1 *)pytalloc_get_ptr(in);
			break;

		case 2:
			PY_CHECK_TYPE(&echo_info2_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info2 = *(struct echo_info2 *)pytalloc_get_ptr(in);
			break;

		case 3:
			PY_CHECK_TYPE(&echo_info3_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info3 = *(struct echo_info3 *)pytalloc_get_ptr(in);
			break;

		case 4:
			PY_CHECK_TYPE(&echo_info4_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info4 = *(struct echo_info4 *)pytalloc_get_ptr(in);
			break;

		case 5:
			PY_CHECK_TYPE(&echo_info5_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info5 = *(struct echo_info5 *)pytalloc_get_ptr(in);
			break;

		case 6:
			PY_CHECK_TYPE(&echo_info6_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info6 = *(struct echo_info6 *)pytalloc_get_ptr(in);
			break;

		case 7:
			PY_CHECK_TYPE(&echo_info7_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->info7 = *(struct echo_info7 *)pytalloc_get_ptr(in);
			break;

		default:
			PyErr_SetString(PyExc_TypeError, "invalid union level value");
			talloc_free(ret);
			ret = NULL;
	}

	return ret;
}


static PyObject *py_echo_Enum2_get_e1(PyObject *obj, void *closure)
{
	struct echo_Enum2 *object = (struct echo_Enum2 *)pytalloc_get_ptr(obj);
	PyObject *py_e1;
	py_e1 = PyInt_FromLong(object->e1);
	return py_e1;
}

static int py_echo_Enum2_set_e1(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_Enum2 *object = (struct echo_Enum2 *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->e1 = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->e1 = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyObject *py_echo_Enum2_get_e2(PyObject *obj, void *closure)
{
	struct echo_Enum2 *object = (struct echo_Enum2 *)pytalloc_get_ptr(obj);
	PyObject *py_e2;
	py_e2 = PyInt_FromLong(object->e2);
	return py_e2;
}

static int py_echo_Enum2_set_e2(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_Enum2 *object = (struct echo_Enum2 *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->e2 = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->e2 = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyGetSetDef py_echo_Enum2_getsetters[] = {
	{ discard_const_p(char, "e1"), py_echo_Enum2_get_e1, py_echo_Enum2_set_e1 },
	{ discard_const_p(char, "e2"), py_echo_Enum2_get_e2, py_echo_Enum2_set_e2 },
	{ NULL }
};

static PyObject *py_echo_Enum2_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_Enum2, type);
}


static PyTypeObject echo_Enum2_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.Enum2",
	.tp_getset = py_echo_Enum2_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_Enum2_new,
};

PyObject *py_import_echo_Enum3(TALLOC_CTX *mem_ctx, int level, union echo_Enum3 *in)
{
	PyObject *ret;

	switch (level) {
		case ECHO_ENUM1:
			ret = PyInt_FromLong(in->e1);
			return ret;

		case ECHO_ENUM2:
			ret = pytalloc_reference_ex(&echo_Enum2_Type, mem_ctx, &in->e2);
			return ret;

	}
	PyErr_SetString(PyExc_TypeError, "unknown union level");
	return NULL;
}

union echo_Enum3 *py_export_echo_Enum3(TALLOC_CTX *mem_ctx, int level, PyObject *in)
{
	union echo_Enum3 *ret = talloc_zero(mem_ctx, union echo_Enum3);
	switch (level) {
		case ECHO_ENUM1:
			if (PyLong_Check(in)) {
				ret->e1 = PyLong_AsLongLong(in);
			} else if (PyInt_Check(in)) {
				ret->e1 = PyInt_AsLong(in);
			} else {
				PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
				  PyInt_Type.tp_name, PyLong_Type.tp_name);
				talloc_free(ret); return NULL;
			}
			break;

		case ECHO_ENUM2:
			PY_CHECK_TYPE(&echo_Enum2_Type, in, talloc_free(ret); return NULL;);
			if (talloc_reference(mem_ctx, pytalloc_get_mem_ctx(in)) == NULL) {
				PyErr_NoMemory();
				talloc_free(ret); return NULL;
			}
			ret->e2 = *(struct echo_Enum2 *)pytalloc_get_ptr(in);
			break;

		default:
			PyErr_SetString(PyExc_TypeError, "invalid union level value");
			talloc_free(ret);
			ret = NULL;
	}

	return ret;
}


static PyObject *py_echo_Surrounding_get_x(PyObject *obj, void *closure)
{
	struct echo_Surrounding *object = (struct echo_Surrounding *)pytalloc_get_ptr(obj);
	PyObject *py_x;
	py_x = PyInt_FromLong(object->x);
	return py_x;
}

static int py_echo_Surrounding_set_x(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_Surrounding *object = (struct echo_Surrounding *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->x = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_echo_Surrounding_get_surrounding(PyObject *obj, void *closure)
{
	struct echo_Surrounding *object = (struct echo_Surrounding *)pytalloc_get_ptr(obj);
	PyObject *py_surrounding;
	py_surrounding = PyList_New(object->x);
	if (py_surrounding == NULL) {
		return NULL;
	}
	{
		int surrounding_cntr_0;
		for (surrounding_cntr_0 = 0; surrounding_cntr_0 < object->x; surrounding_cntr_0++) {
			PyObject *py_surrounding_0;
			py_surrounding_0 = PyInt_FromLong(object->surrounding[surrounding_cntr_0]);
			PyList_SetItem(py_surrounding, surrounding_cntr_0, py_surrounding_0);
		}
	}
	return py_surrounding;
}

static int py_echo_Surrounding_set_surrounding(PyObject *py_obj, PyObject *value, void *closure)
{
	struct echo_Surrounding *object = (struct echo_Surrounding *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyList_Type, value, return -1;);
	{
		int surrounding_cntr_0;
		object->surrounding = talloc_array_ptrtype(pytalloc_get_mem_ctx(py_obj), object->surrounding, PyList_GET_SIZE(value));
		if (!object->surrounding) { return -1;; }
		talloc_set_name_const(object->surrounding, "ARRAY: object->surrounding");
		for (surrounding_cntr_0 = 0; surrounding_cntr_0 < PyList_GET_SIZE(value); surrounding_cntr_0++) {
			PY_CHECK_TYPE(&PyInt_Type, PyList_GET_ITEM(value, surrounding_cntr_0), return -1;);
			object->surrounding[surrounding_cntr_0] = PyInt_AsLong(PyList_GET_ITEM(value, surrounding_cntr_0));
		}
	}
	return 0;
}

static PyGetSetDef py_echo_Surrounding_getsetters[] = {
	{ discard_const_p(char, "x"), py_echo_Surrounding_get_x, py_echo_Surrounding_set_x },
	{ discard_const_p(char, "surrounding"), py_echo_Surrounding_get_surrounding, py_echo_Surrounding_set_surrounding },
	{ NULL }
};

static PyObject *py_echo_Surrounding_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct echo_Surrounding, type);
}


static PyTypeObject echo_Surrounding_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.Surrounding",
	.tp_getset = py_echo_Surrounding_getsetters,
	.tp_methods = NULL,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_echo_Surrounding_new,
};


static bool pack_py_echo_AddOne_args_in(PyObject *args, PyObject *kwargs, struct echo_AddOne *r)
{
	PyObject *py_in_data;
	const char *kwnames[] = {
		"in_data", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_AddOne", discard_const_p(char *, kwnames), &py_in_data)) {
		return false;
	}

	PY_CHECK_TYPE(&PyInt_Type, py_in_data, return false;);
	r->in.in_data = PyInt_AsLong(py_in_data);
	return true;
}

static PyObject *unpack_py_echo_AddOne_args_out(struct echo_AddOne *r)
{
	PyObject *result;
	PyObject *py_out_data;
	py_out_data = PyInt_FromLong(*r->out.out_data);
	result = py_out_data;
	return result;
}

static bool pack_py_echo_EchoData_args_in(PyObject *args, PyObject *kwargs, struct echo_EchoData *r)
{
	PyObject *py_in_data;
	const char *kwnames[] = {
		"in_data", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_EchoData", discard_const_p(char *, kwnames), &py_in_data)) {
		return false;
	}

	PY_CHECK_TYPE(&PyList_Type, py_in_data, return false;);
	r->in.len = PyList_GET_SIZE(py_in_data);
	PY_CHECK_TYPE(&PyList_Type, py_in_data, return false;);
	{
		int in_data_cntr_0;
		r->in.in_data = talloc_array_ptrtype(r, r->in.in_data, PyList_GET_SIZE(py_in_data));
		if (!r->in.in_data) { return false;; }
		talloc_set_name_const(r->in.in_data, "ARRAY: r->in.in_data");
		for (in_data_cntr_0 = 0; in_data_cntr_0 < PyList_GET_SIZE(py_in_data); in_data_cntr_0++) {
			PY_CHECK_TYPE(&PyInt_Type, PyList_GET_ITEM(py_in_data, in_data_cntr_0), return false;);
			r->in.in_data[in_data_cntr_0] = PyInt_AsLong(PyList_GET_ITEM(py_in_data, in_data_cntr_0));
		}
	}
	return true;
}

static PyObject *unpack_py_echo_EchoData_args_out(struct echo_EchoData *r)
{
	PyObject *result;
	PyObject *py_out_data;
	py_out_data = PyList_New(r->in.len);
	if (py_out_data == NULL) {
		return NULL;
	}
	{
		int out_data_cntr_0;
		for (out_data_cntr_0 = 0; out_data_cntr_0 < r->in.len; out_data_cntr_0++) {
			PyObject *py_out_data_0;
			py_out_data_0 = PyInt_FromLong(r->out.out_data[out_data_cntr_0]);
			PyList_SetItem(py_out_data, out_data_cntr_0, py_out_data_0);
		}
	}
	result = py_out_data;
	return result;
}

static bool pack_py_echo_SinkData_args_in(PyObject *args, PyObject *kwargs, struct echo_SinkData *r)
{
	PyObject *py_data;
	const char *kwnames[] = {
		"data", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_SinkData", discard_const_p(char *, kwnames), &py_data)) {
		return false;
	}

	PY_CHECK_TYPE(&PyList_Type, py_data, return false;);
	r->in.len = PyList_GET_SIZE(py_data);
	PY_CHECK_TYPE(&PyList_Type, py_data, return false;);
	{
		int data_cntr_0;
		r->in.data = talloc_array_ptrtype(r, r->in.data, PyList_GET_SIZE(py_data));
		if (!r->in.data) { return false;; }
		talloc_set_name_const(r->in.data, "ARRAY: r->in.data");
		for (data_cntr_0 = 0; data_cntr_0 < PyList_GET_SIZE(py_data); data_cntr_0++) {
			PY_CHECK_TYPE(&PyInt_Type, PyList_GET_ITEM(py_data, data_cntr_0), return false;);
			r->in.data[data_cntr_0] = PyInt_AsLong(PyList_GET_ITEM(py_data, data_cntr_0));
		}
	}
	return true;
}

static PyObject *unpack_py_echo_SinkData_args_out(struct echo_SinkData *r)
{
	PyObject *result;
	result = Py_None;
	Py_INCREF(result);
	return result;
}

static bool pack_py_echo_SourceData_args_in(PyObject *args, PyObject *kwargs, struct echo_SourceData *r)
{
	PyObject *py_len;
	const char *kwnames[] = {
		"len", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_SourceData", discard_const_p(char *, kwnames), &py_len)) {
		return false;
	}

	PY_CHECK_TYPE(&PyInt_Type, py_len, return false;);
	r->in.len = PyInt_AsLong(py_len);
	return true;
}

static PyObject *unpack_py_echo_SourceData_args_out(struct echo_SourceData *r)
{
	PyObject *result;
	PyObject *py_data;
	py_data = PyList_New(r->in.len);
	if (py_data == NULL) {
		return NULL;
	}
	{
		int data_cntr_0;
		for (data_cntr_0 = 0; data_cntr_0 < r->in.len; data_cntr_0++) {
			PyObject *py_data_0;
			py_data_0 = PyInt_FromLong(r->out.data[data_cntr_0]);
			PyList_SetItem(py_data, data_cntr_0, py_data_0);
		}
	}
	result = py_data;
	return result;
}

static bool pack_py_echo_TestCall_args_in(PyObject *args, PyObject *kwargs, struct echo_TestCall *r)
{
	PyObject *py_s1;
	const char *kwnames[] = {
		"s1", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_TestCall", discard_const_p(char *, kwnames), &py_s1)) {
		return false;
	}

	r->in.s1 = talloc_ptrtype(r, r->in.s1);
	if (PyUnicode_Check(py_s1)) {
		r->in.s1 = PyString_AS_STRING(PyUnicode_AsEncodedString(py_s1, "utf-8", "ignore"));
	} else if (PyString_Check(py_s1)) {
		r->in.s1 = PyString_AS_STRING(py_s1);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected string or unicode object, got %s", Py_TYPE(py_s1)->tp_name);
		return false;
	}
	return true;
}

static PyObject *unpack_py_echo_TestCall_args_out(struct echo_TestCall *r)
{
	PyObject *result;
	PyObject *py_s2;
	if (*r->out.s2 == NULL) {
		py_s2 = Py_None;
		Py_INCREF(py_s2);
	} else {
		if (*r->out.s2 == NULL) {
			py_s2 = Py_None;
			Py_INCREF(py_s2);
		} else {
			py_s2 = PyUnicode_Decode(*r->out.s2, strlen(*r->out.s2), "utf-8", "ignore");
		}
	}
	result = py_s2;
	return result;
}

static bool pack_py_echo_TestCall2_args_in(PyObject *args, PyObject *kwargs, struct echo_TestCall2 *r)
{
	PyObject *py_level;
	const char *kwnames[] = {
		"level", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_TestCall2", discard_const_p(char *, kwnames), &py_level)) {
		return false;
	}

	PY_CHECK_TYPE(&PyInt_Type, py_level, return false;);
	r->in.level = PyInt_AsLong(py_level);
	return true;
}

static PyObject *unpack_py_echo_TestCall2_args_out(struct echo_TestCall2 *r)
{
	PyObject *result;
	PyObject *py_info;
	py_info = py_import_echo_Info(r->out.info, r->in.level, r->out.info);
	if (py_info == NULL) {
		return NULL;
	}
	result = py_info;
	if (NT_STATUS_IS_ERR(r->out.result)) {
		PyErr_SetNTSTATUS(r->out.result);
		return NULL;
	}

	return result;
}

static bool pack_py_echo_TestSleep_args_in(PyObject *args, PyObject *kwargs, struct echo_TestSleep *r)
{
	PyObject *py_seconds;
	const char *kwnames[] = {
		"seconds", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_TestSleep", discard_const_p(char *, kwnames), &py_seconds)) {
		return false;
	}

	PY_CHECK_TYPE(&PyInt_Type, py_seconds, return false;);
	r->in.seconds = PyInt_AsLong(py_seconds);
	return true;
}

static PyObject *unpack_py_echo_TestSleep_args_out(struct echo_TestSleep *r)
{
	PyObject *result;
	result = PyInt_FromLong(r->out.result);
	return result;
}

static bool pack_py_echo_TestEnum_args_in(PyObject *args, PyObject *kwargs, struct echo_TestEnum *r)
{
	PyObject *py_foo1;
	PyObject *py_foo2;
	PyObject *py_foo3;
	const char *kwnames[] = {
		"foo1", "foo2", "foo3", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO:echo_TestEnum", discard_const_p(char *, kwnames), &py_foo1, &py_foo2, &py_foo3)) {
		return false;
	}

	r->in.foo1 = talloc_ptrtype(r, r->in.foo1);
	if (PyLong_Check(py_foo1)) {
		*r->in.foo1 = PyLong_AsLongLong(py_foo1);
	} else if (PyInt_Check(py_foo1)) {
		*r->in.foo1 = PyInt_AsLong(py_foo1);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return false;
	}
	r->in.foo2 = talloc_ptrtype(r, r->in.foo2);
	PY_CHECK_TYPE(&echo_Enum2_Type, py_foo2, return false;);
	if (talloc_reference(r, pytalloc_get_mem_ctx(py_foo2)) == NULL) {
		PyErr_NoMemory();
		return false;
	}
	r->in.foo2 = (struct echo_Enum2 *)pytalloc_get_ptr(py_foo2);
	r->in.foo3 = talloc_ptrtype(r, r->in.foo3);
	{
		union echo_Enum3 *foo3_switch_1;
		foo3_switch_1 = py_export_echo_Enum3(r, *r->in.foo1, py_foo3);
		if (foo3_switch_1 == NULL) {
			return false;
		}
		r->in.foo3 = foo3_switch_1;
	}
	return true;
}

static PyObject *unpack_py_echo_TestEnum_args_out(struct echo_TestEnum *r)
{
	PyObject *result;
	PyObject *py_foo1;
	PyObject *py_foo2;
	PyObject *py_foo3;
	result = PyTuple_New(3);
	py_foo1 = PyInt_FromLong(*r->out.foo1);
	PyTuple_SetItem(result, 0, py_foo1);
	py_foo2 = pytalloc_reference_ex(&echo_Enum2_Type, r->out.foo2, r->out.foo2);
	PyTuple_SetItem(result, 1, py_foo2);
	py_foo3 = py_import_echo_Enum3(r->out.foo3, *r->out.foo1, r->out.foo3);
	if (py_foo3 == NULL) {
		return NULL;
	}
	PyTuple_SetItem(result, 2, py_foo3);
	return result;
}

static bool pack_py_echo_TestSurrounding_args_in(PyObject *args, PyObject *kwargs, struct echo_TestSurrounding *r)
{
	PyObject *py_data;
	const char *kwnames[] = {
		"data", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_TestSurrounding", discard_const_p(char *, kwnames), &py_data)) {
		return false;
	}

	r->in.data = talloc_ptrtype(r, r->in.data);
	PY_CHECK_TYPE(&echo_Surrounding_Type, py_data, return false;);
	if (talloc_reference(r, pytalloc_get_mem_ctx(py_data)) == NULL) {
		PyErr_NoMemory();
		return false;
	}
	r->in.data = (struct echo_Surrounding *)pytalloc_get_ptr(py_data);
	return true;
}

static PyObject *unpack_py_echo_TestSurrounding_args_out(struct echo_TestSurrounding *r)
{
	PyObject *result;
	PyObject *py_data;
	py_data = pytalloc_reference_ex(&echo_Surrounding_Type, r->out.data, r->out.data);
	result = py_data;
	return result;
}

static bool pack_py_echo_TestDoublePointer_args_in(PyObject *args, PyObject *kwargs, struct echo_TestDoublePointer *r)
{
	PyObject *py_data;
	const char *kwnames[] = {
		"data", NULL
	};

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:echo_TestDoublePointer", discard_const_p(char *, kwnames), &py_data)) {
		return false;
	}

	r->in.data = talloc_ptrtype(r, r->in.data);
	if (py_data == Py_None) {
		*r->in.data = NULL;
	} else {
		*r->in.data = NULL;
		if (py_data == Py_None) {
			**r->in.data = NULL;
		} else {
			**r->in.data = talloc_ptrtype(r, **r->in.data);
			PY_CHECK_TYPE(&PyInt_Type, py_data, return false;);
			***r->in.data = PyInt_AsLong(py_data);
		}
	}
	return true;
}

static PyObject *unpack_py_echo_TestDoublePointer_args_out(struct echo_TestDoublePointer *r)
{
	PyObject *result;
	result = PyInt_FromLong(r->out.result);
	return result;
}

const struct PyNdrRpcMethodDef py_ndr_rpcecho_methods[] = {
	{ "AddOne", "S.AddOne(in_data) -> out_data", (py_dcerpc_call_fn)dcerpc_echo_AddOne_r, (py_data_pack_fn)pack_py_echo_AddOne_args_in, (py_data_unpack_fn)unpack_py_echo_AddOne_args_out, 0, &ndr_table_rpcecho },
	{ "EchoData", "S.EchoData(in_data) -> out_data", (py_dcerpc_call_fn)dcerpc_echo_EchoData_r, (py_data_pack_fn)pack_py_echo_EchoData_args_in, (py_data_unpack_fn)unpack_py_echo_EchoData_args_out, 1, &ndr_table_rpcecho },
	{ "SinkData", "S.SinkData(data) -> None", (py_dcerpc_call_fn)dcerpc_echo_SinkData_r, (py_data_pack_fn)pack_py_echo_SinkData_args_in, (py_data_unpack_fn)unpack_py_echo_SinkData_args_out, 2, &ndr_table_rpcecho },
	{ "SourceData", "S.SourceData(len) -> data", (py_dcerpc_call_fn)dcerpc_echo_SourceData_r, (py_data_pack_fn)pack_py_echo_SourceData_args_in, (py_data_unpack_fn)unpack_py_echo_SourceData_args_out, 3, &ndr_table_rpcecho },
	{ "TestCall", "S.TestCall(s1) -> s2", (py_dcerpc_call_fn)dcerpc_echo_TestCall_r, (py_data_pack_fn)pack_py_echo_TestCall_args_in, (py_data_unpack_fn)unpack_py_echo_TestCall_args_out, 4, &ndr_table_rpcecho },
	{ "TestCall2", "S.TestCall2(level) -> info", (py_dcerpc_call_fn)dcerpc_echo_TestCall2_r, (py_data_pack_fn)pack_py_echo_TestCall2_args_in, (py_data_unpack_fn)unpack_py_echo_TestCall2_args_out, 5, &ndr_table_rpcecho },
	{ "TestSleep", "S.TestSleep(seconds) -> result", (py_dcerpc_call_fn)dcerpc_echo_TestSleep_r, (py_data_pack_fn)pack_py_echo_TestSleep_args_in, (py_data_unpack_fn)unpack_py_echo_TestSleep_args_out, 6, &ndr_table_rpcecho },
	{ "TestEnum", "S.TestEnum(foo1, foo2, foo3) -> (foo1, foo2, foo3)", (py_dcerpc_call_fn)dcerpc_echo_TestEnum_r, (py_data_pack_fn)pack_py_echo_TestEnum_args_in, (py_data_unpack_fn)unpack_py_echo_TestEnum_args_out, 7, &ndr_table_rpcecho },
	{ "TestSurrounding", "S.TestSurrounding(data) -> data", (py_dcerpc_call_fn)dcerpc_echo_TestSurrounding_r, (py_data_pack_fn)pack_py_echo_TestSurrounding_args_in, (py_data_unpack_fn)unpack_py_echo_TestSurrounding_args_out, 8, &ndr_table_rpcecho },
	{ "TestDoublePointer", "S.TestDoublePointer(data) -> result", (py_dcerpc_call_fn)dcerpc_echo_TestDoublePointer_r, (py_data_pack_fn)pack_py_echo_TestDoublePointer_args_in, (py_data_unpack_fn)unpack_py_echo_TestDoublePointer_args_out, 9, &ndr_table_rpcecho },
	{ NULL }
};

static PyObject *interface_rpcecho_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_rpcecho);
}

#define PY_DOC_RPCECHO "Simple echo pipe"
static PyTypeObject rpcecho_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "echo.rpcecho",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "rpcecho(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_RPCECHO,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_rpcecho_new,
};

static PyMethodDef echo_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initecho(void)
{
	PyObject *m;
	PyObject *dep_talloc;
	PyObject *dep_samba_dcerpc_base;

	dep_talloc = PyImport_ImportModule("talloc");
	if (dep_talloc == NULL)
		return;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	Object_Type = (PyTypeObject *)PyObject_GetAttrString(dep_talloc, "Object");
	if (Object_Type == NULL)
		return;

	echo_info1_Type.tp_base = Object_Type;

	echo_info2_Type.tp_base = Object_Type;

	echo_info3_Type.tp_base = Object_Type;

	echo_info4_Type.tp_base = Object_Type;

	echo_info5_Type.tp_base = Object_Type;

	echo_info6_Type.tp_base = Object_Type;

	echo_info7_Type.tp_base = Object_Type;

	echo_Enum2_Type.tp_base = Object_Type;

	echo_Surrounding_Type.tp_base = Object_Type;

	rpcecho_InterfaceType.tp_base = ClientConnection_Type;

	if (PyType_Ready(&echo_info1_Type) < 0)
		return;
	if (PyType_Ready(&echo_info2_Type) < 0)
		return;
	if (PyType_Ready(&echo_info3_Type) < 0)
		return;
	if (PyType_Ready(&echo_info4_Type) < 0)
		return;
	if (PyType_Ready(&echo_info5_Type) < 0)
		return;
	if (PyType_Ready(&echo_info6_Type) < 0)
		return;
	if (PyType_Ready(&echo_info7_Type) < 0)
		return;
	if (PyType_Ready(&echo_Enum2_Type) < 0)
		return;
	if (PyType_Ready(&echo_Surrounding_Type) < 0)
		return;
	if (PyType_Ready(&rpcecho_InterfaceType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&rpcecho_InterfaceType, py_ndr_rpcecho_methods))
		return;

#ifdef PY_INFO1_PATCH
	PY_INFO1_PATCH(&echo_info1_Type);
#endif
#ifdef PY_INFO2_PATCH
	PY_INFO2_PATCH(&echo_info2_Type);
#endif
#ifdef PY_INFO3_PATCH
	PY_INFO3_PATCH(&echo_info3_Type);
#endif
#ifdef PY_INFO4_PATCH
	PY_INFO4_PATCH(&echo_info4_Type);
#endif
#ifdef PY_INFO5_PATCH
	PY_INFO5_PATCH(&echo_info5_Type);
#endif
#ifdef PY_INFO6_PATCH
	PY_INFO6_PATCH(&echo_info6_Type);
#endif
#ifdef PY_INFO7_PATCH
	PY_INFO7_PATCH(&echo_info7_Type);
#endif
#ifdef PY_ENUM2_PATCH
	PY_ENUM2_PATCH(&echo_Enum2_Type);
#endif
#ifdef PY_SURROUNDING_PATCH
	PY_SURROUNDING_PATCH(&echo_Surrounding_Type);
#endif
#ifdef PY_RPCECHO_PATCH
	PY_RPCECHO_PATCH(&rpcecho_InterfaceType);
#endif

	m = Py_InitModule3("echo", echo_methods, "echo DCE/RPC");
	if (m == NULL)
		return;

	PyModule_AddObject(m, "ECHO_ENUM2", PyInt_FromLong(ECHO_ENUM2));
	PyModule_AddObject(m, "ECHO_ENUM1_32", PyInt_FromLong(ECHO_ENUM1_32));
	PyModule_AddObject(m, "ECHO_ENUM2_32", PyInt_FromLong(ECHO_ENUM2_32));
	PyModule_AddObject(m, "ECHO_ENUM1", PyInt_FromLong(ECHO_ENUM1));
	Py_INCREF((PyObject *)(void *)&echo_info1_Type);
	PyModule_AddObject(m, "info1", (PyObject *)(void *)&echo_info1_Type);
	Py_INCREF((PyObject *)(void *)&echo_info2_Type);
	PyModule_AddObject(m, "info2", (PyObject *)(void *)&echo_info2_Type);
	Py_INCREF((PyObject *)(void *)&echo_info3_Type);
	PyModule_AddObject(m, "info3", (PyObject *)(void *)&echo_info3_Type);
	Py_INCREF((PyObject *)(void *)&echo_info4_Type);
	PyModule_AddObject(m, "info4", (PyObject *)(void *)&echo_info4_Type);
	Py_INCREF((PyObject *)(void *)&echo_info5_Type);
	PyModule_AddObject(m, "info5", (PyObject *)(void *)&echo_info5_Type);
	Py_INCREF((PyObject *)(void *)&echo_info6_Type);
	PyModule_AddObject(m, "info6", (PyObject *)(void *)&echo_info6_Type);
	Py_INCREF((PyObject *)(void *)&echo_info7_Type);
	PyModule_AddObject(m, "info7", (PyObject *)(void *)&echo_info7_Type);
	Py_INCREF((PyObject *)(void *)&echo_Enum2_Type);
	PyModule_AddObject(m, "Enum2", (PyObject *)(void *)&echo_Enum2_Type);
	Py_INCREF((PyObject *)(void *)&echo_Surrounding_Type);
	PyModule_AddObject(m, "Surrounding", (PyObject *)(void *)&echo_Surrounding_Type);
	Py_INCREF((PyObject *)(void *)&rpcecho_InterfaceType);
	PyModule_AddObject(m, "rpcecho", (PyObject *)(void *)&rpcecho_InterfaceType);
#ifdef PY_MOD_ECHO_PATCH
	PY_MOD_ECHO_PATCH(m);
#endif

}
