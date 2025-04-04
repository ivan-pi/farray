#include <assert.h>
#include <hpy.h>

#include <math.h> // for HUGE_VAL, NAN
#include <stdint.h> // int32_t, int64_t

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


//
// Bitwise operators
//

extern void farray_invert_int32_t(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_invert_int64_t(const CFI_cdesc_t *x, CFI_cdesc_t *y);
extern void farray_invert_Bool(const CFI_cdesc_t *x, CFI_cdesc_t *y);

extern void farray_and_int32_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_and_int64_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_and_Bool(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);

extern void farray_or_int32_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_or_int64_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_or_Bool(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);

extern void farray_xor_int32_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_xor_int64_t(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);
extern void farray_xor_Bool(const CFI_cdesc_t *x1, const CFI_cdesc_t *x2, CFI_cdesc_t *y);

extern void farray_add_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_subtract_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_multiply_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_divide_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_hypot_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);


extern void farray_pow_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_pow_dp_int32(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_pow_dp_int64(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);

extern void farray_mod_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);

//
// Comparison operators
//

extern void farray_lt_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_le_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_gt_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_ge_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_eq_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);
extern void farray_ne_dp_dp(const CFI_cdesc_t *x1, const CFI_cdesc_t* x2, CFI_cdesc_t *y);

extern void farray_ones_dp(CFI_cdesc_t *y);
extern void farray_zeros_dp(CFI_cdesc_t *y);
extern void farray_eye_dp(CFI_cdesc_t *y);


#define FARRAY_CAST(X) ((CFI_cdesc_t *) &((X)->a))

#define FARRAY_UNARY_CALL(FUNC,X,Y) \
    FUNC(FARRAY_CAST(X), FARRAY_CAST(Y))
#define FARRAY_BINARY_CALL(FUNC,X1,X2,Y) \
    FUNC(FARRAY_CAST(X1), FARRAY_CAST(X2), FARRAY_CAST(Y))

// BEGIN: dtype
typedef struct {
    CFI_type_t type;
} dtype;
HPyType_HELPERS(dtype);
// END: dtype

// BEGIN: FArray
// Maximum supported array rank
#define FARRAY_MAX_RANK 2
typedef struct {
    CFI_CDESC_T(FARRAY_MAX_RANK) a;
} FArray;
HPyType_HELPERS(FArray)
// END: FArray


// Create a new empty array Y with the same properties as X
static int FArray_new_like(const FArray *X, FArray *Y) {

    CFI_index_t lb[FARRAY_MAX_RANK];
    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < X->a.rank; k++) {
        lb[k] = 1;
        ub[k] = X->a.dim[k].extent;
    }

    int status;
    status = CFI_establish(FARRAY_CAST(Y), NULL, CFI_attribute_allocatable,
                        X->a.type, 0, X->a.rank, NULL);

    if (status == CFI_SUCCESS) {
        status = CFI_allocate(FARRAY_CAST(Y), lb, ub, 0);
    }
    return status;
}

// Create a new empty array Y with the same properties as X
static int FArray_new_allocatable(
        CFI_type_t type,
        int rank,
        const CFI_index_t extent[],
        FArray *Y) {

    assert(rank <= FARRAY_MAX_RANK);

    CFI_index_t lb[FARRAY_MAX_RANK];
    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < rank; k++) {
        lb[k] = 1;
        ub[k] = extent[k];
    }

    int status;
    status = CFI_establish(FARRAY_CAST(Y), NULL, CFI_attribute_allocatable,
                        type, 0, rank, NULL);
    if (status == CFI_SUCCESS) {
        status = CFI_allocate(FARRAY_CAST(Y), lb, ub, 0);
    }
    return status;
}

// Create a new empty array Y with the same properties as X
static int FArray_new_pointer(
        CFI_type_t type,
        int rank,
        const CFI_index_t extent[],
        FArray *Y) {

    assert(rank <= FARRAY_MAX_RANK);

    CFI_index_t lb[FARRAY_MAX_RANK];
    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < rank; k++) {
        lb[k] = 1;
        ub[k] = extent[k];
    }

    int status;
    status = CFI_establish(FARRAY_CAST(Y), NULL, CFI_attribute_pointer,
                        type, 0, rank, NULL);
    if (status == CFI_SUCCESS) {
        status = CFI_allocate(FARRAY_CAST(Y), lb, ub, 0);
    }
    return status;
}

// BEGIN: members

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
    return HPyLong_FromLong(ctx, 42);
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
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }
    FARRAY_UNARY_CALL(farray_transpose_dp,A,B);
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
            "max dimensions", HPyLong_FromInt32_t(ctx, FARRAY_MAX_RANK));

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
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    FARRAY_UNARY_CALL(farray_transpose_dp, A, B);
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
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    // FIMXME: for unary functions like abs and similar we should
    // have a static inline layer which does the type dispatch

    if (x->a.type == CFI_type_double) {
        FARRAY_UNARY_CALL(farray_abs_dp,x,y);
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
    return HPyLong_FromLong(ctx, 42 + (long)(HPy_ssize_t)closure);
}

static int FArray_z_set(HPyContext *ctx, HPy self, HPy value, void *closure)
{
    FArray *arr = FArray_AsStruct(ctx, self);
    long current = 42 + (long)(HPy_ssize_t)closure;
    long target = HPyLong_AsLong(ctx, value);  // assume no exception
    //arr->y += target - current;
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

    const CFI_index_t ub[2] = {(CFI_index_t) x, (CFI_index_t) y};

    int status = FArray_new_allocatable(CFI_type_double, 2, ub, arr);

    return h_arr;
}


#define FARRAY_UNARY_OP(OP, SLOT, METHOD, RESULT_TYPE) \
HPyDef_SLOT(FArray_##OP, HPy_##SLOT) \
static HPy FArray_##OP##_impl(HPyContext *ctx, HPy hx)         \
{ \
    FArray *x = FArray_AsStruct(ctx, hx); \
    FArray *y; \
    /* FIXME: class should come using other means */ \
    HPy hy = HPy_New(ctx, HPy_Type(ctx,hx), &y); \
    if (HPy_IsNull(hy)) { \
        return HPy_NULL; \
    } \
    int status = FArray_new_like(x, y); \
    if (status != CFI_SUCCESS) return HPy_NULL; \
    FARRAY_UNARY_CALL(METHOD,x,y); \
    return hy; \
}

FARRAY_UNARY_OP(absolute,nb_absolute,farray_abs_dp,CFI_type_double)
FARRAY_UNARY_OP(negative,nb_negative,farray_negative_dp,CFI_type_double)
FARRAY_UNARY_OP(positive,nb_positive,farray_positive_dp,CFI_type_double)

HPyDef_SLOT(FArray_float, HPy_nb_float)
static HPy FArray_float_impl(HPyContext *ctx, HPy hx)
{
    FArray *x = FArray_AsStruct(ctx, hx);
    if (x->a.rank != 0) {
        return HPy_NULL;
    }
    double result;
    switch(x->a.type) {
        case CFI_type_double: result = *((double *) x->a.base_addr); break;
        case CFI_type_float: result = *((float *) x->a.base_addr); break;
        case CFI_type_int32_t: result = *((int32_t *) x->a.base_addr); break;
        case CFI_type_int64_t: result = *((int64_t *) x->a.base_addr); break;
        case CFI_type_Bool: result = *((bool *) x->a.base_addr) ? 1.0 : 0.0; break;
        default:
            HPy_FatalError(ctx, "cfi type not implemented for float()");
    }
    return HPyFloat_FromDouble(ctx, result); \
}

HPyDef_SLOT(FArray_int, HPy_nb_int)
static HPy FArray_int_impl(HPyContext *ctx, HPy hx)
{
    FArray *x = FArray_AsStruct(ctx, hx);
    if (x->a.rank != 0) {
        return HPy_NULL;
    }
    long int result;
    switch(x->a.type) {
        case CFI_type_double: result = *((double *) x->a.base_addr); break;
        case CFI_type_float: result = *((float *) x->a.base_addr); break;
        case CFI_type_int32_t: result = *((int32_t *) x->a.base_addr); break;
        case CFI_type_int64_t: result = *((int64_t *) x->a.base_addr); break;
        case CFI_type_Bool: result = *((bool *) x->a.base_addr) ? 1 : 0; break;
        default:
            HPy_FatalError(ctx, "cfi type not implemented for int()");
    }
    return HPyLong_FromLong(ctx, result); \
}

HPyDef_SLOT(FArray_index, HPy_nb_index)
static HPy FArray_index_impl(HPyContext *ctx, HPy hx)
{
    FArray *x = FArray_AsStruct(ctx, hx);
    if (x->a.rank != 0) {
        return HPy_NULL;
    }
    long int result;
    switch(x->a.type) {
        case CFI_type_double: result = *((double *) x->a.base_addr); break;
        case CFI_type_float: result = *((float *) x->a.base_addr); break;
        case CFI_type_int32_t: result = *((int32_t *) x->a.base_addr); break;
        case CFI_type_int64_t: result = *((int64_t *) x->a.base_addr); break;
        case CFI_type_Bool: result = *((bool *) x->a.base_addr) ? 1 : 0; break;
        default:
            HPy_FatalError(ctx, "cfi type not implemented for index()");
    }
    return HPyLong_FromLong(ctx, result); \
}

HPyDef_SLOT(FArray_invert, HPy_nb_invert)
static HPy FArray_invert_impl(HPyContext *ctx, HPy hx)
{
    FArray *x = FArray_AsStruct(ctx, hx);
    FArray *y;

    /* FIXME: class should come using other means */
    HPy hy = HPy_New(ctx, HPy_Type(ctx,hx), &y);
    if (HPy_IsNull(hy)) {
        return HPy_NULL;
    }

    int stat = FArray_new_like(x,y);
    if (stat != CFI_SUCCESS) {
        return HPy_NULL;
    }

    switch(x->a.type) {
    case CFI_type_int32_t: FARRAY_UNARY_CALL(farray_invert_int32_t,x,y); break;
    case CFI_type_int64_t: FARRAY_UNARY_CALL(farray_invert_int64_t,x,y); break;
    case CFI_type_Bool: FARRAY_UNARY_CALL(farray_invert_Bool,x,y); break;
    default:
        HPy_FatalError(ctx, "cfi type not implemented for invert()");
    }
    return hy; \
}

// HPyDef_SLOT(FArray_bool, HPy_nb_bool)
// static int FArray_bool_impl(HPyContext *ctx, HPy hx)
// {
//     FArray *x = FArray_AsStruct(ctx, hx);
//     if (x->a.rank != 0) {
//         return HPy_NULL;
//     }

//     int result;
//     switch(x->a.type) {
//         case CFI_type_double: result = *((double *) x->a.base_addr) != 0.0; break;
//         case CFI_type_float: result = *((float *) x->a.base_addr) != 0.0f; break;
//         case CFI_type_int32_t: result = *((int32_t *) x->a.base_addr) != 0; break;
//         case CFI_type_int64_t: result = *((int64_t *) x->a.base_addr) != 0; break;
//         case CFI_type_Bool: result = *((bool *) x->a.base_addr); break;
//         default:
//             HPy_FatalError(ctx, "cfi type not implemented for bool()");
//     }
//     return result;
// }

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
    if (n != B->a.dim[0].extent) {
        // shape mismatch, inner dimension does not agree
        return HPy_NULL;
    }
    int k = B->a.dim[1].extent;

    const CFI_index_t ub[2] = {m, k};

    int status = FArray_new_allocatable(CFI_type_double, 2, ub, C);
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    // matrix multiplication
    FARRAY_BINARY_CALL(farray_mm_dp,A,B,C);
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
    int status = FArray_new_like(A, C); \
    FARRAY_BINARY_CALL(METHOD,A,B,C); \
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
    const CFI_index_t ub[2] = {m, n};

    int status = FArray_new_allocatable(CFI_type_Bool, 2, ub, C);
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    switch (op) {
    case HPy_EQ: FARRAY_BINARY_CALL(farray_eq_dp_dp,A,B,C); break;
    case HPy_NE: FARRAY_BINARY_CALL(farray_ne_dp_dp,A,B,C); break;
    case HPy_LT: FARRAY_BINARY_CALL(farray_lt_dp_dp,A,B,C); break;
    case HPy_GT: FARRAY_BINARY_CALL(farray_gt_dp_dp,A,B,C); break;
    case HPy_LE: FARRAY_BINARY_CALL(farray_le_dp_dp,A,B,C); break;
    case HPy_GE: FARRAY_BINARY_CALL(farray_ge_dp_dp,A,B,C); break;
    default:
        HPy_FatalError(ctx, "Invalid value for FArray_richcompare");
    }

    return hc;
}

// END: slots

// BEGIN: defines
static HPyDef *FArray_defines[] = {
    &FArray_z, // FIXME: delete z method
    &FArray_shape,
    &FArray_size,
    &FArray_transpose, // .T
    &FArray_ndim, // rank
    &FArray_version,
    &FArray_elem_len,
    &FArray_attribute,
    &FArray_f_type,
    &FArray_new,
    &FArray_absolute,
    &FArray_positive,
    &FArray_negative,
    &FArray_invert,
    &FArray_float,
    &FArray_int,
    &FArray_index,
//    &FArray_bool,
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
HPyDef_SLOT(farray_exec, HPy_mod_exec)
static int farray_exec_impl(HPyContext *ctx, HPy m) {
    if (!HPyHelpers_AddType(ctx, m, "FArray", &FArray_spec, NULL)) {
        return -1;
    }
    return 0; // success
}
// END: add_type

// MACROS needed for stringizing the supported array rank
// https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
#define xstr(s) str(s)
#define str(s) #s

// FIXME: this should be a varargs functions
HPyDef_METH(ones, "ones", HPyFunc_O)
static HPy ones_impl(HPyContext *ctx, HPy self, HPy shape)
{

    if (!HPyTuple_Check(ctx, shape)) {
        HPyErr_SetString(ctx, ctx->h_TypeError,"shape must be a tuple");
        return HPy_NULL;
    }

    HPy_ssize_t rank = HPy_Length(ctx,shape);
    if (rank > FARRAY_MAX_RANK) {
        HPyErr_SetString(ctx, ctx->h_TypeError,
            "len(shape) exceeds maximum supported rank (" xstr(FARRAY_MAX_RANK) ")");
        return HPy_NULL;
    }

    // FIXME: perhaps we should retrieve the type from the context instead?
    HPy cls = HPyType_FromSpec(ctx,&FArray_spec ,NULL);
    if (HPy_IsNull(cls)) {
        return HPy_NULL;
    }

    FArray *A;
    HPy hA = HPy_New(ctx, cls, &A);
    if (HPy_IsNull(hA)) {
        return HPy_NULL;
    }

    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < rank; k++) {
        ub[k] = HPyLong_AsInt32_t(ctx,HPy_GetItem_i(ctx,shape,k));
    }
    int status = FArray_new_allocatable(CFI_type_double,2,ub,A);
    if (status != CFI_SUCCESS) {
        HPy_FatalError(ctx, "CFI_allocate failed");
        return HPy_NULL;
    }

    farray_ones_dp(FARRAY_CAST(A));

    return hA;
}

// FIXME: this should be a varargs functions
HPyDef_METH(ones_like, "ones_like", HPyFunc_O)
static HPy ones_like_impl(HPyContext *ctx, HPy self, HPy hx)
{
    FArray *X = FArray_AsStruct(ctx,hx);

    FArray *Y;
    HPy hy = HPy_New(ctx,HPy_Type(ctx,hx), &Y);
    if (HPy_IsNull(hy)) {
        return HPy_NULL;
    }

    // FIXME: report failure reason
    if (!FArray_new_like(X,Y)) {
        farray_ones_dp(FARRAY_CAST(Y));
    } else {
        HPyErr_SetString(ctx, ctx->h_RuntimeError,
            "ones_like failed due for CFI reasons");
        return HPy_NULL;
    }
    return hy;
}

// FIXME: this should be a varargs functions
HPyDef_METH(zeros, "zeros", HPyFunc_O)
static HPy zeros_impl(HPyContext *ctx, HPy self, HPy shape)
{

    if (!HPyTuple_Check(ctx, shape)) {
        HPyErr_SetString(ctx, ctx->h_TypeError,"shape must be a tuple");
        return HPy_NULL;
    }

    HPy_ssize_t rank = HPy_Length(ctx,shape);
    if (rank > FARRAY_MAX_RANK) {
        HPyErr_SetString(ctx, ctx->h_TypeError,
            "len(shape) exceeds maximum supported rank (" xstr(FARRAY_MAX_RANK) ")");
        return HPy_NULL;
    }

    // FIXME: perhaps we should retrieve the type from the context instead?
    HPy cls = HPyType_FromSpec(ctx,&FArray_spec ,NULL);
    if (HPy_IsNull(cls)) {
        return HPy_NULL;
    }

    FArray *A;
    HPy hA = HPy_New(ctx, cls, &A);
    if (HPy_IsNull(hA)) {
        return HPy_NULL;
    }

    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < rank; k++) {
        ub[k] = HPyLong_AsInt32_t(ctx,HPy_GetItem_i(ctx,shape,k));
    }

    int status = FArray_new_allocatable(CFI_type_double, rank, ub, A);
    if (status != CFI_SUCCESS) {
        return HPy_NULL;
    }

    farray_zeros_dp(FARRAY_CAST(A));

    return hA;
}

// FIXME: this should be a varargs functions
HPyDef_METH(zeros_like, "zeros_like", HPyFunc_O)
static HPy zeros_like_impl(HPyContext *ctx, HPy self, HPy hx)
{
    FArray *X = FArray_AsStruct(ctx,hx);

    FArray *Y;
    HPy hy = HPy_New(ctx,HPy_Type(ctx,hx), &Y);
    if (HPy_IsNull(hy)) {
        return HPy_NULL;
    }

    if (!FArray_new_like(X,Y)) {
        farray_zeros_dp(FARRAY_CAST(Y));
    } else {
        HPyErr_SetString(ctx, ctx->h_RuntimeError,
            "zeros_like failed for CFI reasons");
        return HPy_NULL;
    }
    return hy;
}

// FIXME: this should be a varargs functions
HPyDef_METH(empty, "empty", HPyFunc_O)
static HPy empty_impl(HPyContext *ctx, HPy self, HPy shape)
{

    if (!HPyTuple_Check(ctx, shape)) {
        HPyErr_SetString(ctx, ctx->h_TypeError,"shape must be a tuple");
        return HPy_NULL;
    }

    HPy_ssize_t rank = HPy_Length(ctx,shape);
    if (rank > FARRAY_MAX_RANK) {
        HPyErr_SetString(ctx, ctx->h_TypeError,
            "len(shape) exceeds maximum supported rank (" xstr(FARRAY_MAX_RANK) ")");
        return HPy_NULL;
    }

    // FIXME: perhaps we should retrieve the type from the context instead?
    HPy cls = HPyType_FromSpec(ctx,&FArray_spec ,NULL);
    if (HPy_IsNull(cls)) {
        return HPy_NULL;
    }

    FArray *A;
    HPy hA = HPy_New(ctx, cls, &A);
    if (HPy_IsNull(hA)) {
        return HPy_NULL;
    }

    // Now the handle is formed, we can do transpose

    int status;
    status = CFI_establish(
        (CFI_cdesc_t *) &(A->a), NULL,  CFI_attribute_allocatable,
        CFI_type_double, 0, (CFI_rank_t) rank, NULL);
    if (status != CFI_SUCCESS) {
        HPy_FatalError(ctx, "CFI_establish failed");
        return HPy_NULL;
    }

    CFI_index_t lb[FARRAY_MAX_RANK];
    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < rank; k++) {
        lb[k] = 1;
        ub[k] = HPyLong_AsInt32_t(ctx,HPy_GetItem_i(ctx,shape,k));
    }

    status = CFI_allocate(FARRAY_CAST(A), lb, ub, 0);
    if (status != CFI_SUCCESS) {
        HPy_FatalError(ctx, "CFI_allocate failed");
        return HPy_NULL;
    }

    return hA;
}

// FIXME: this should be a varargs functions
HPyDef_METH(empty_like, "empty_like", HPyFunc_O)
static HPy empty_like_impl(HPyContext *ctx, HPy self, HPy hx)
{
    FArray *X = FArray_AsStruct(ctx,hx);

    FArray *Y;
    HPy hy = HPy_New(ctx,HPy_Type(ctx,hx), &Y);
    if (HPy_IsNull(hy)) {
        return HPy_NULL;
    }

    if (FArray_new_like(X,Y)) {
        HPyErr_SetString(ctx, ctx->h_RuntimeError,
            "empty_like failed due for CFI reasons");
        return HPy_NULL;
    }
    return hy;
}


// FIXME: this should be a varargs functions
HPyDef_METH(eye, "eye", HPyFunc_O)
static HPy eye_impl(HPyContext *ctx, HPy self, HPy hnrows)
{

    int nrows = HPyLong_AsInt32_t(ctx,hnrows);

    // FIXME: perhaps we should retrieve the type from the context instead?
    HPy cls = HPyType_FromSpec(ctx,&FArray_spec ,NULL);
    if (HPy_IsNull(cls)) {
        return HPy_NULL;
    }

    FArray *A;
    HPy hA = HPy_New(ctx, cls, &A);
    if (HPy_IsNull(hA)) {
        return HPy_NULL;
    }

    // FIXME: generalize type based on dtype

    int status;
    status = CFI_establish(
        (CFI_cdesc_t *) &(A->a), NULL,  CFI_attribute_allocatable,
        CFI_type_double, 0, 2, NULL);
    if (status != CFI_SUCCESS) {
        HPy_FatalError(ctx, "CFI_establish failed");
        return HPy_NULL;
    }

    CFI_index_t lb[FARRAY_MAX_RANK];
    CFI_index_t ub[FARRAY_MAX_RANK];
    for (int k = 0; k < 2; k++) {
        lb[k] = 1;
        ub[k] = nrows;
    }

    status = CFI_allocate(FARRAY_CAST(A), lb, ub, 0);
    if (status != CFI_SUCCESS) {
        HPy_FatalError(ctx, "CFI_allocate failed");
        return HPy_NULL;
    }

    // Set diagonal to zero
    farray_eye_dp(FARRAY_CAST(A));

    return hA;
}


// FIXME: how do we expose constants as Python extension module
// entities. Or should we just create them in Python?

const double farray_e   = 2.7182818284590452353602874;
const double farray_inf = HUGE_VAL;
const double farray_nan = NAN;
const double farray_pi  = 3.1415926535897932384626433;

static HPyDef *mod_defines[] = {
    &farray_exec, // 'farray_exec' is generated by the HPyDef_SLOT macro
    &matrix_transpose,
    &ones,
    &ones_like,
    &zeros,
    &zeros_like,
    &empty,
    &empty_like,
    &eye,
    &allocated,
    &elem_abs,
    &capabilities, /* dictionary */
    NULL,
};

static HPyModuleDef moduledef = {
    .defines = mod_defines,
    .size = 0,
    .doc = "A simple HPy array object in Fortran",
    .legacy_methods = NULL
};

HPy_MODINIT(farray, moduledef)
