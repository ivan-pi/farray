# farray

Array class based upon Fortran arrays

Prerequites:
- gfortran
- [HPy](https://hpyproject.org/)

To install HPy use:
```
python3 -m pip install hpy
```

To start experimenting with the extension class, type
```
make
python scripts/demo.py
```

To run the extension, you may need to add the current folder to the Python path, i.e.

```
export PYTHONPATH=`pwd`
```
