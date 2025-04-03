# demo.py
import farray as far

print(far.capabilities())

a = far.FArray(10,20)
print(a.ndim, far.allocated(a))

b = far.matrix_transpose(a)
print(b.ndim, far.allocated(b))

print(a.shape)
print(b.shape)

c = a @ b

c = a.__matmul__(b)

print(c.shape)

d = c + far.abs(c)
print(d.shape)

r = far.ones((4,5))
print(r.shape)
