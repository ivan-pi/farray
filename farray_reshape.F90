subroutine farray_copy_to(a,b)
    use, intrinsic :: iso_c_binding, only: c_double
    real(c_double), intent(in), target, contiguous :: a(..)
    real(c_double), intent(out) :: b(:)

    real(c_double), pointer :: aflat(:)

    select rank(a)
    rank(1)
        b = a
    rank(2)
        aflat(1:size(a)) => a
        b = aflat
    rank(3)
        aflat(1:size(a)) => a
        b = aflat
    rank(4)
        aflat(1:size(a)) => a
        b = aflat
    rank default
       error stop "Unsupported rank"
    end select

end subroutine
