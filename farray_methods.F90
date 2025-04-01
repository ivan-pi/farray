subroutine farray_mm_dp(a,b,c) bind(c)
    use, intrinsic :: iso_c_binding, only: c_double
    implicit none
    real(c_double), intent(in) :: A(:,:), B(:,:)
    real(c_double), intent(out) :: C(:,:)
    C = matmul(A,B)
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
