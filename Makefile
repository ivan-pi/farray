

CC = gcc-14
export CC

FC=gfortran
FFLAGS=-g -Og -Wall -Werror -fcheck=all

.PHONY: build
build: farray.c farray_methods.o
	python setup.py --hpy-abi=universal build_ext -i

farray_methods.o: farray_methods.F90
	$(FC) $(FFLAGS) -c $<

# This target requires gfortran-15 to produce
# correct descriptors.

farray_methods.h: farray_methods.F90
	gfortran -fsyntax-only -fc-prototypes $< > $@
