

CC = gcc-14
export CC

FC=gfortran
FFLAGS=-g -Og -Wall -Werror -fcheck=all

.PHONY: build
build: simple_type.c farray_methods.o
	python setup.py build_ext -i

farray_methods.o: farray_methods.F90
	$(FC) $(FFLAGS) -c $<
