#include <assert.h>
#include <hpy.h>

#include <math.h> // for HUGE_VAL, NAN

#include <ISO_Fortran_binding.h>

// Fortran implementations from farray_methods.F90
extern void farray_mm_dp(const CFI_cdesc_t *a,
                         const CFI_cdesc_t *b,
                               CFI_cdesc_t *c);

extern void farray_transpose_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);

//
// Element-wise functions
//
extern void farray_abs_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_acos_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_acosh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_asin_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_asinh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_atan_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
//extern void farray_atan2_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_atanh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_cos_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_cosh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_exp_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
//extern void farray_expm1_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_log_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_log10_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_negative_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_positive_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_sin_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_sinh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_square_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_sqrt_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_tan_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_tanh_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_reciprocal_dp(const CFI_cdesc_t *x, CFI_cdesc_t *y);

extern void farray_add_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_subtract_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_multiply_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_divide_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_hypot_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);


extern void farray_pow_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_pow_dp_int32(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_pow_dp_int64(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);

extern void farray_mod_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);


extern void farray_lt_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_le_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_gt_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_ge_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_eq_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_ne_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);

// Maximum supported array rank
#define FARRAY_MAX_RANK 2

// BEGIN: FArray
typedef struct {
    // FIXME: delete x and x
    long x;
    long y;
    CFI_CDESC_T(FARRAY_MAX_RANK) a;
    int usign; // Extra flag needed to represent unsigned types
} FArray;
HPyType_HELPERS(FArray)
// END: FArray

static inline CFI_cdesc_t* FArray_get_descriptor(HPyContext *ctx, HPy self) {
    FArray *tmp = FArray_AsStruct(ctx,self);
    return (CFI_cdesc_t *) &(tmp->a);
}

// BEGIN: members
HPyDef_MEMBER(FArray_x, "x", HPyMember_LONG, offsetof(FArray, x))
HPyDef_MEMBER(FArray_y, "y", HPyMember_LONG, offsetof(FArray, y))

// FIXME: the HPy type depends on the size of the integers in the underlying
// implementation of ISO_Fortran_binding. This needs to be corrected to
// use other compilers

HPyDef_MEMBER(FArray_ndim, "ndim", HPyMember_BYTE, offsetof(FArray, a.rank),.readonly=true,
    .doc="Number of dimensions")

// Members to query properties of the underlying Fortran descriptor
HPyDef_MEMBER(FArray_version, "cfi_version", HPyMember_INT, offsetof(FArray, a.version),.readonly=true,
    .doc="CFI version integer")
HPyDef_MEMBER(FArray_elem_len, "elem_len", HPyMember_LONG, offsetof(FArray, a.elem_len),.readonly=true,
    .doc="Element length in bytes")
HPyDef_MEMBER(FArray_attribute, "cfi_attribute", HPyMember_BYTE, offsetof(FArray, a.attribute),.readonly=true,
    .doc="CFI array attribute (allocatable, pointer, other)")
HPyDef_MEMBER(FArray_f_type, "cfi_type", HPyMember_SHORT,offsetof(FArray,a.type),.readonly=true,
    .doc="CFI type enumerator")


// dtype    - Data type of the array elements
// device   - Hardware device the array data resides on
// mT       - Transpose of a matrix (or a stack of matrices)
// ndim     - Number of array dimensions (axes)
// shape    - Array dimensions
// size     - Number of elements in an array
// T        - Transpose of the array

// END: members

// BEGIN: methods
HPyDef_METH(FArray_foo, "foo", HPyFunc_NOARGS)
static HPy FArray_foo_impl(HPyContext *ctx, HPy self)
{
    FArray *arr = FArray_AsStruct(ctx, self);
    return HPyLong_FromLong(ctx, arr->x * 10 + arr->y);
}


HPyDef_GET(FArray_shape, "shape",.doc="Shape of the array")
static HPy FArray_shape_get(HPyContext *ctx, HPy self, void* closure)
{
    FArray *A = FArray_AsStruct(ctx, self);

    HPyTupleBuilder builder = HPyTupleBuilder_New(ctx,A->a.rank);

    for (int k = 0; k < A->a.rank; k++) {
        HPyTupleBuilder_Set(ctx,builder,k,
            HPyLong_FromLong(ctx,(long int) A->a.dim[k].extent));
    }

    HPy hshape = HPyTupleBuilder_Build(ctx,builder);
    if (HPy_IsNull(hshape)) {
        return HPy_NULL;
    }
    return hshape;
}

HPyDef_GET(FArray_size, "size",.doc="Size of the array")
static HPy FArray_size_get(HPyContext *ctx, HPy self, void *closure)
{
    FArray *A = FArray_AsStruct(ctx, self);

    //const long x = (long) A->a.dim[0].extent;
    //const long y = (long) A->a.dim[1].extent;

    size_t sz;

    // FIXME: handle zero-sized arrays

    sz = 1;
    for (int k = 0; k < A->a.rank; k++) {
        sz *= A->a.dim[k].extent;
    }

    return HPyLong_FromSize_t(ctx, sz);
}

HPyDef_GET(FArray_transpose, "T",.doc="Transpose of the array")
static HPy FArray_transpose_get(HPyContext *ctx, HPy self, void *closure)
{
    FArray *A = FArray_AsStruct(ctx, self);

    // This operation only defined for matrices
    if (A->a.rank != 2) {
        return HPy_NULL;
    }

    FArray *B;
    HPy hB = HPy_New(ctx, HPy_Type(ctx,self), &B);
    if (HPy_IsNull(hB)) {
        return HPy_NULL;
    }

    int status;
    status = CFI_establish(
        (CFI_cdesc_t *) &(B->a), NULL,  CFI_attribute_allocatable,
        A->a.type, 0, A->a.rank, NULL);
    assert(status == CFI_SUCCESS);
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    CFI_index_t lb[FARRAY_MAX_RANK], ub[FARRAY_MAX_RANK];
    const int mr = A->a.rank;
    for (int i = 0; i < mr; i++) {
        lb[mr - i - 1] = A->a.dim[i].lower_bound;
        ub[mr - i - 1] = A->a.dim[i].lower_bound + A->a.dim[i].extent - 1;
    }
    status = CFI_allocate((CFI_cdesc_t *) &(B->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    // B = A^T
    farray_transpose_dp((CFI_cdesc_t *) &(A->a), (CFI_cdesc_t *) &(B->a));

    return hB;
}

HPyDef_METH(allocated, "allocated", HPyFunc_O)
static HPy allocated_impl(HPyContext *ctx, HPy self, HPy arg)
{
    FArray *arr = FArray_AsStruct(ctx, arg);

    long alloc = arr->a.base_addr != NULL;
    return HPyBool_FromLong(ctx, alloc);

}

HPyDef_METH(capabilities, "capabilities", HPyFunc_NOARGS)
static HPy capabilities_impl(HPyContext *ctx, HPy self) {

// https://data-apis.org/array-api/latest/API_specification/generated/array_api.info.capabilities.html#array_api.info.capabilities

    HPy hd = HPy_BuildValue(ctx, "{s:O, s:O, s:O}",
            "boolean indexing", HPyBool_FromBool(ctx,false),
            "data-dependent shapes", HPyBool_FromBool(ctx,false),
            "max dimensions", HPyLong_FromInt32_t(ctx, 2));

    if (HPy_IsNull(hd)) {
        return HPy_NULL;
    }

    return hd;
}

HPyDef_METH(matrix_transpose, "matrix_transpose", HPyFunc_O)
static HPy matrix_transpose_impl(HPyContext *ctx, HPy self, HPy arg)
{

    FArray *A = FArray_AsStruct(ctx,arg);
    FArray *B;

    HPy h_transpose = HPy_New(ctx, HPy_Type(ctx,arg), &B);
    if (HPy_IsNull(h_transpose)) {
        return HPy_NULL;
    }

    // Now the handle is formed, we can do transpose

    int status;
    status = CFI_establish(
        (CFI_cdesc_t *) &(B->a), NULL,  CFI_attribute_allocatable,
        A->a.type, 0, A->a.rank, NULL);
    assert(status == CFI_SUCCESS);

    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    CFI_index_t lb[FARRAY_MAX_RANK], ub[FARRAY_MAX_RANK];
    const int mr = A->a.rank;
    for (int i = 0; i < mr; i++) {
        lb[mr - i - 1] = A->a.dim[i].lower_bound;
        ub[mr - i - 1] = A->a.dim[i].lower_bound + A->a.dim[i].extent - 1;
    }

    status = CFI_allocate((CFI_cdesc_t *) &(B->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);

    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    B->x = A->y;
    B->y = A->x;

    // B = A^T
    farray_transpose_dp((CFI_cdesc_t *) &(A->a), (CFI_cdesc_t *) &(B->a));

    return h_transpose;
}

HPyDef_METH(elem_abs, "abs", HPyFunc_O)
static HPy elem_abs_impl(HPyContext *ctx, HPy self, HPy arg)
{

    FArray *x = FArray_AsStruct(ctx,arg);
    FArray *y;

    HPy hy = HPy_New(ctx, HPy_Type(ctx,arg), &y);
    if (HPy_IsNull(hy)) {
        return HPy_NULL;
    }

    int status;
    status = CFI_establish(
        (CFI_cdesc_t *) &(y->a), NULL,  CFI_attribute_allocatable,
        x->a.type, 0, x->a.rank, NULL);
    assert(status == CFI_SUCCESS);

    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    CFI_index_t lb[FARRAY_MAX_RANK], ub[FARRAY_MAX_RANK];
    const int mr = x->a.rank;
    for (int i = 0; i < mr; i++) {
        lb[mr - i - 1] = x->a.dim[i].lower_bound;
        ub[mr - i - 1] = x->a.dim[i].lower_bound + x->a.dim[i].extent - 1;
    }

    status = CFI_allocate((CFI_cdesc_t *) &(y->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);

    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    y->x = x->y;
    y->y = x->x;

    // FIMXME: for unary functions like abs and similar we should
    // have a static inline layer which does the type dispatch

    if (x->a.type == CFI_type_double) {
        farray_abs_dp(
            (CFI_cdesc_t *) &(x->a),
            (CFI_cdesc_t *) &(y->a));
    } else {
        return HPy_NULL;
    }

    return hy;
}
// END: methods

// BEGIN: getset
HPyDef_GETSET(FArray_z, "z", .closure=(void *)1000)
static HPy FArray_z_get(HPyContext *ctx, HPy self, void *closure)
{
    FArray *arr = FArray_AsStruct(ctx, self);
    return HPyLong_FromLong(ctx, arr->x*10 + arr->y + (long)(HPy_ssize_t)closure);
}

static int FArray_z_set(HPyContext *ctx, HPy self, HPy value, void *closure)
{
    FArray *arr = FArray_AsStruct(ctx, self);
    long current = arr->x*10 + arr->y + (long)(HPy_ssize_t)closure;
    long target = HPyLong_AsLong(ctx, value);  // assume no exception
    arr->y += target - current;
    return 0;
}
// END: getset

// BEGIN: slots
HPyDef_SLOT(FArray_new, HPy_tp_new)
static HPy FArray_new_impl(HPyContext *ctx, HPy cls, const HPy *args,
        HPy_ssize_t nargs, HPy kw)
{
    long x, y;
    assert(nargs == 2);
    if (!HPyArg_Parse(ctx, NULL, args, nargs, "ll", &x, &y)) {
        return HPy_NULL;
    }

    FArray *arr;
    HPy h_arr = HPy_New(ctx, cls, &arr);
    if (HPy_IsNull(h_arr)) {
        return HPy_NULL;
    }

    const CFI_index_t lb[2] = {1, 1};
    const CFI_index_t ub[2] = {(CFI_index_t) x, (CFI_index_t) y};

    int status;
    status = CFI_establish((CFI_cdesc_t *)&(arr->a), NULL,  CFI_attribute_allocatable,
                        CFI_type_double, 0, 2, NULL);
    assert(status == CFI_SUCCESS);

    status = CFI_allocate((CFI_cdesc_t *) &(arr->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);

    arr->x = x;
    arr->y = y;

    return h_arr;
}


HPyDef_SLOT(FArray_matrix_multiply, HPy_nb_matrix_multiply)
static HPy FArray_matrix_multiply_impl(HPyContext *ctx, HPy ha, HPy hb)
{
    FArray *A = FArray_AsStruct(ctx, ha);
    FArray *B = FArray_AsStruct(ctx, hb);

    FArray *C;

    // FIXME: class should come using other means

    HPy hc = HPy_New(ctx, HPy_Type(ctx,ha), &C);
    if (HPy_IsNull(hc)) {
        return HPy_NULL;
    }

    int m = A->a.dim[0].extent;
    int n = A->a.dim[1].extent;
    assert(n == B->a.dim[0].extent);
    int k = B->a.dim[1].extent;

    const CFI_index_t lb[2] = {1, 1};
    const CFI_index_t ub[2] = {m, k};

    int status;
    status = CFI_establish((CFI_cdesc_t *)&(C->a), NULL,  CFI_attribute_allocatable,
                        CFI_type_double, 0, 2, NULL);
    assert(status == CFI_SUCCESS);

    status = CFI_allocate((CFI_cdesc_t *) &(C->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);

    C->x = m;
    C->y = k;


    // matrix multiplication
    farray_mm_dp(
        (CFI_cdesc_t *) &(A->a), (CFI_cdesc_t *) &(B->a),
        (CFI_cdesc_t *) &(C->a));

    return hc;
}

#define FARRAY_BINARY_OP(OP, SLOT, METHOD, RESULT_TYPE) \
HPyDef_SLOT(FArray_##OP, HPy_##SLOT) \
static HPy FArray_##OP##_impl(HPyContext *ctx, HPy ha, HPy hb)         \
{ \
    FArray *A = FArray_AsStruct(ctx, ha); \
    FArray *B = FArray_AsStruct(ctx, hb); \
    FArray *C; \
    /* FIXME: class should come using other means */ \
    HPy hc = HPy_New(ctx, HPy_Type(ctx,ha), &C); \
    if (HPy_IsNull(hc)) { \
        return HPy_NULL; \
    } \
    int m = A->a.dim[0].extent; \
    int n = A->a.dim[1].extent; \
    const CFI_index_t lb[2] = {1, 1}; \
    const CFI_index_t ub[2] = {m, n}; \
    int status; \
    status = CFI_establish((CFI_cdesc_t *)&(C->a), NULL,  CFI_attribute_allocatable, \
                        RESULT_TYPE, 0, 2, NULL); \
    assert(status == CFI_SUCCESS); \
    status = CFI_allocate((CFI_cdesc_t *) &(C->a), lb, ub, 0); \
    assert(status == CFI_SUCCESS); \
    C->x = m; \
    C->y = n; \
    METHOD ( \
        (CFI_cdesc_t *) &(A->a), (CFI_cdesc_t *) &(B->a), \
        (CFI_cdesc_t *) &(C->a)); \
    return hc; \
}

FARRAY_BINARY_OP(add,nb_add,farray_add_dp, CFI_type_double)
FARRAY_BINARY_OP(subtract,nb_subtract,farray_subtract_dp, CFI_type_double)
FARRAY_BINARY_OP(multiply,nb_multiply,farray_multiply_dp, CFI_type_double)
FARRAY_BINARY_OP(true_divide,nb_true_divide,farray_divide_dp, CFI_type_double)
FARRAY_BINARY_OP(remainder,nb_remainder,farray_mod_dp_dp, CFI_type_double)

// FIXME: other types

// FIXME: we may need to patch around this issue:
//        https://github.com/hpyproject/hpy/issues/483
//FARRAY_BINARY_OP(power,farray_pow_dp_dp)

HPyDef_SLOT(FArray_richcompare, HPy_tp_richcompare)
static HPy FArray_richcompare_impl(HPyContext *ctx, HPy ha, HPy hb, HPy_RichCmpOp op)
{
    FArray *A = FArray_AsStruct(ctx, ha);
    FArray *B = FArray_AsStruct(ctx, hb);
    FArray *C;
    /* FIXME: class should come using other means */
    HPy hc = HPy_New(ctx, HPy_Type(ctx,ha), &C);
    if (HPy_IsNull(hc)) {
        return HPy_NULL;
    }
    int m = A->a.dim[0].extent;
    int n = A->a.dim[1].extent;
    const CFI_index_t lb[2] = {1, 1};
    const CFI_index_t ub[2] = {m, n};
    int status;
    status = CFI_establish((CFI_cdesc_t *)&(C->a), NULL,  CFI_attribute_allocatable,
                        CFI_type_Bool, 0, 2, NULL);
    assert(status == CFI_SUCCESS);
    status = CFI_allocate((CFI_cdesc_t *) &(C->a), lb, ub, 0);
    assert(status == CFI_SUCCESS);
    C->x = m;
    C->y = n;

    do {
        switch (op) {
        case HPy_EQ:
            farray_eq_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        case HPy_NE:
            farray_ne_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        case HPy_LT:
            farray_lt_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        case HPy_GT:
            farray_gt_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        case HPy_LE:
            farray_le_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        case HPy_GE:
            farray_ge_dp_dp(
                (CFI_cdesc_t *) &(A->a),
                (CFI_cdesc_t *) &(B->a),
                (CFI_cdesc_t *) &(C->a));
            break;
        default:
            HPy_FatalError(ctx, "Invalid value for HPy_RichCmpOp");
        }
    } while (0);

    return hc;
}

// END: slots

// BEGIN: defines
static HPyDef *FArray_defines[] = {
    &FArray_x,
    &FArray_y,
    &FArray_z,
    &FArray_shape,
    &FArray_size,
    &FArray_transpose, // .T
    &FArray_ndim, // rank
    &FArray_version,
    &FArray_elem_len,
    &FArray_attribute,
    &FArray_f_type,
    &FArray_new,
    &FArray_matrix_multiply,
    &FArray_add,
    &FArray_subtract,
    &FArray_multiply,
    &FArray_true_divide,
    &FArray_remainder,
    &FArray_richcompare,
    &FArray_foo,
    NULL
};
// END: defines

// BEGIN: spec
static HPyType_Spec FArray_spec = {
    .name = "farray.FArray",
    .basicsize = sizeof(FArray),
    .builtin_shape = FArray_SHAPE,
    .defines = FArray_defines
};
// END: spec

// BEGIN: add_type
HPyDef_SLOT(simple_exec, HPy_mod_exec)
static int simple_exec_impl(HPyContext *ctx, HPy m) {
    if (!HPyHelpers_AddType(ctx, m, "FArray", &FArray_spec, NULL)) {
        return -1;
    }
    return 0; // success
}
// END: add_type

const double farray_e   = 2.7182818284590452353602874713526624977572470936999;
const double farray_inf = HUGE_VAL;
const double farray_nan = NAN;
const double farray_pi  = 3.1415926535897932384626433;


static HPyDef *mod_defines[] = {
    &simple_exec, // 'simple_exec' is generated by the HPyDef_SLOT macro
    &matrix_transpose,
    &allocated,
    &capabilities,
    &elem_abs,
    NULL,
};

static HPyModuleDef moduledef = {
    .defines = mod_defines,
    .size = 0,
    .doc = "A simple HPy array object in Fortran",
    .legacy_methods = NULL
};

HPy_MODINIT(farray, moduledef)
