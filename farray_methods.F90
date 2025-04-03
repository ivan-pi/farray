subroutine farray_mm_dp(a,b,c) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    implicit none
    real(c_double), intent(in) :: a(:,:), b(:,:)
    real(c_double), intent(out) :: c(:,:)
    c = matmul(a,b)
end subroutine

subroutine farray_transpose_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = transpose(x)
end subroutine

!
! Element-wise functions
!

subroutine farray_abs_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = abs(x)
end subroutine

subroutine farray_acos_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = acos(x)
end subroutine

subroutine farray_acosh_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = acosh(x)
end subroutine

subroutine farray_add_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 + x2
end subroutine

subroutine farray_asin_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = asin(x)
end subroutine

subroutine farray_asinh_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = asinh(x)
end subroutine


subroutine farray_cos_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = cos(x)
end subroutine

subroutine farray_cosh_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = cosh(x)
end subroutine


subroutine farray_divide_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1/x2
end subroutine

subroutine farray_exp_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = exp(x)
end subroutine

subroutine farray_log_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = log(x)
end subroutine

subroutine farray_log10_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = log10(x)
end subroutine

subroutine farray_hypot_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:)
    real(c_double), intent(out) :: x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = hypot(x1,x2)
end subroutine

subroutine farray_multiply_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:)
    real(c_double), intent(out) :: x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 * x2
end subroutine

subroutine farray_negative_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = -x
end subroutine

subroutine farray_positive_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = +x
end subroutine

subroutine farray_reciprocal_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = real(1,c_double) / x
end subroutine

subroutine farray_subtract_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:)
    real(c_double), intent(out) :: x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 - x2
end subroutine

subroutine farray_sin_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = sin(x)
end subroutine

subroutine farray_sinh_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = sinh(x)
end subroutine

subroutine farray_square_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x**2
end subroutine

subroutine farray_sqrt_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = sqrt(x)
end subroutine

subroutine farray_tan_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = tan(x)
end subroutine

subroutine farray_tanh_dp(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = tanh(x)
end subroutine


subroutine farray_pow_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 ** x2
end subroutine

subroutine farray_pow_dp_int32(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_int32_t
    real(c_double), intent(in) :: x1(:,:)
    integer(c_int32_t), intent(in) :: x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 ** x2
end subroutine

subroutine farray_pow_dp_int64(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_int64_t
    real(c_double), intent(in) :: x1(:,:)
    integer(c_int64_t), intent(in) :: x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = x1 ** x2
end subroutine

subroutine farray_mod_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    real(c_double), intent(out) :: y(:,:)
    y = mod(x1, x2)
end subroutine

!
! Comparison operators
!

subroutine farray_lt_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .lt. x2
end subroutine

subroutine farray_le_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .le. x2
end subroutine

subroutine farray_gt_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .gt. x2
end subroutine

subroutine farray_ge_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .ge. x2
end subroutine

subroutine farray_eq_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .eq. x2
end subroutine

subroutine farray_ne_dp_dp(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double, c_bool
    real(c_double), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .ne. x2
end subroutine

!
! Bitwise operators
!

subroutine farray_invert_int32_t(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int32_t
    integer(c_int32_t), intent(in) :: x(:,:)
    integer(c_int32_t), intent(out) :: y(:,:)
    y = not(x)
end subroutine

subroutine farray_invert_int64_t(x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int64_t
    integer(c_int64_t), intent(in) :: x(:,:)
    integer(c_int64_t), intent(out) :: y(:,:)
    y = not(x)
end subroutine

subroutine farray_invert_Bool(x,y) bind(c,name="farray_invert_Bool")
    use, intrinsic :: iso_c_binding, only: c_bool
    logical(c_bool), intent(in) :: x(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = .not. x
end subroutine


subroutine farray_and_int32_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int32_t
    integer(c_int32_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int32_t), intent(out) :: y(:,:)
    y = iand(x1,x2)
end subroutine

subroutine farray_and_int64_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int64_t
    integer(c_int64_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int64_t), intent(out) :: y(:,:)
    y = iand(x1,x2)
end subroutine

subroutine farray_and_Bool(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_bool
    logical(c_bool), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .and. x2
end subroutine


subroutine farray_or_int32_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int32_t
    integer(c_int32_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int32_t), intent(out) :: y(:,:)
    y = ior(x1,x2)
end subroutine

subroutine farray_or_int64_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int64_t
    integer(c_int64_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int64_t), intent(out) :: y(:,:)
    y = ior(x1,x2)
end subroutine

subroutine farray_or_Bool(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_bool
    logical(c_bool), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .or. x2
end subroutine

subroutine farray_xor_int32_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int32_t
    integer(c_int32_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int32_t), intent(out) :: y(:,:)
    y = ieor(x1,x2)
end subroutine

subroutine farray_xor_int64_t(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int64_t
    integer(c_int64_t), intent(in) :: x1(:,:), x2(:,:)
    integer(c_int64_t), intent(out) :: y(:,:)
    y = ieor(x1,x2)
end subroutine

subroutine farray_xor_Bool(x1,x2,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_bool
    logical(c_bool), intent(in) :: x1(:,:), x2(:,:)
    logical(c_bool), intent(out) :: y(:,:)
    y = x1 .neqv. x2
end subroutine


subroutine farray_ones_dp(y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(out) :: y(:,:)
    y = 1.0_c_double
end subroutine

subroutine farray_zeros_dp(y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(out) :: y(:,:)
    y = 0.0_c_double
end subroutine
