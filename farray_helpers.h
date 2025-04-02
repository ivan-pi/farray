
#include <ISO_Fortran_binding.h>

// FIXME: generalize to other compilers

static bool farray_is_bool(CFI_type_t type) {
    switch (type) {
        case CFI_type_Bool:
            return true;
        default:
            return false;
    }
}

static bool farray_is_signed_integer(CFI_type_t type) {
    switch (type) {
        case CFI_type_int8_t:
        case CFI_type_int16_t:
        case CFI_type_int32_t:
        case CFI_type_int64_t:
            return true;
        default:
            return false;
    }
}

static bool farray_is_integral(CFI_type_t type) {
    return farray_is_signed_integer(type);
}

static bool farray_is_real_floating(CFI_type_t type) {
    switch (type) {
        case CFI_type_float:
        case CFI_type_double:
            return true;
        default:
            return false;
    }
}

static bool farray_is_complex_floating(CFI_type_t type) {
    switch (type) {
        case CFI_type_float_Complex:
        case CFI_type_double_Complex:
            return true;
        default:
            return false;
    }
}

static bool farray_is_numeric(CFI_type_t type) {
    switch (type) {
        case CFI_type_int8_t:
        case CFI_type_int16_t:
        case CFI_type_int32_t:
        case CFI_type_int64_t:
        case CFI_type_float:
        case CFI_type_double:
        case CFI_type_float_Complex:
        case CFI_type_double_Complex:
            return true;
        default:
            return false;
    }
}
