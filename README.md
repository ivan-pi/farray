# farray

Experimental Python array class implemented on top of Fortran arrays

The goal is to cover a decent subset of the [Python array API standard](https://data-apis.org/array-api/latest/index.html).

Prerequisites:
- gfortran (Fortran 2018 support is needed)
- Python interpreter
- [HPy](https://hpyproject.org/)
- make

To install HPy use:
```
python3 -m pip install hpy
```

To start experimenting with the array class, type
```
make
python scripts/demo.py
```
The default make target builds the extension module.

To use the extension module you may need to add the current folder to the Python path, i.e.

```
export PYTHONPATH=`pwd`
```

