# demo.py

import farray as far

class finfo:

    def __init__(self,type,/):

        self._bits = 64
        self._eps = 0.0
        self._max = 0.0
        self._min = 0.0
        self._smallest_normal = 0.0
        self._dtype = type


print(far.capabilities())

a = far.FArray(10,20)
print(a.ndim, far.allocated(a), a.x, a.y)

b = far.matrix_transpose(a)
print(b.ndim, far.allocated(b), b.x, b.y)

print(a.shape)
print(b.shape)

c = a @ b
print(c.shape)

d = c + far.abs(c)
print(d.shape)

