# setup.py

from setuptools import setup, Extension
from os import path

DIR = path.dirname(__file__)
setup(
    name="hpy-farray",
    hpy_ext_modules=[
        #Extension('quickstart', sources=[path.join(DIR, 'quickstart.c')]),
        Extension('farray',
            sources=[path.join(DIR, 'farray.c')],
            extra_link_args=['farray_methods.o', '-lgfortran'])
    ],
    setup_requires=['hpy'],
)
