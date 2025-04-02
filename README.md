# farray

Experimental Python array class implemented on top of Fortran arrays

The goal is to cover a decent subset the [Python array API standard](https://data-apis.org/array-api/latest/index.html).

Prerequisites:
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

