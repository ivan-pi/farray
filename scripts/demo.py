# demo.py


import simple_type as fp

class finfo:

    def __init__(self,type,/):

        self._bits = 64
        self._eps = 0.0
        self._max = 0.0
        self._min = 0.0
        self._smallest_normal = 0.0
        self._dtype = type


print(fp.capabilities())

a = fp.FArray(10,20)
print(a.ndim, fp.allocated(a), a.x, a.y)

b = fp.matrix_transpose(a)
print(b.ndim, fp.allocated(b), b.x, b.y)

print(a.shape)
print(b.shape)

c = a @ b
print(c.shape)

d = c + fp.abs(c)
print(d.shape)

