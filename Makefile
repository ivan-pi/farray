

CC = gcc-14
export CC

FC=gfortran
FFLAGS=-g -Og -Wall -fcheck=all

fobjs = farray_methods.o farray_permute_dims.o

.PHONY: build
build: farray.c $(fobjs) setup.py
	python setup.py build_ext -i

farray_methods.o: farray_methods.F90
	$(FC) $(FFLAGS) -c $^

farray_permute_dims.o: farray_permute_dims.F90
	$(FC) $(FFLAGS) -c $^

# This target requires gfortran-15 to produce
# correct descriptors.

farray_methods.h: farray_methods.F90
	gfortran -fsyntax-only -fc-prototypes $< > $@
