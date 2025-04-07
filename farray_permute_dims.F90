subroutine farray_permute_dims_2_dp(order,x,y) bind(c)
    use, intrinsic :: iso_c_binding, only: c_int, c_double
    integer(c_int), intent(in) :: order(2)
    real(c_double), intent(in) :: x(:,:)
    real(c_double), intent(out) :: y(:,:)

    integer(c_int) :: new_shape(2)

    associate(sx => shape(x))
        new_shape(1:2) = sx(order)
        y = reshape(x,shape=new_shape(1:2),order=order)
    end associate

end subroutine

