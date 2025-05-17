Laboratory work 1: 
Variant 22

Project description
____________________________________________________________________________________________________________

Implementation of a library for working with rectangular matrices in C language supporting basic operations:
- Matrix addition
- Matrix multiplication
- Matrix transpose
____________________________________________________________________________________________________________
Project structure

├── inc/               # Header files

├── src/               # Source files

└── test/              # Unit tests
____________________________________________________________________________________________________________

Building
gcc -o matrix input.c error.c double.c complex.c integer.c matrix.c ui.c main.c
matrix
_____________________________________________________________________________________________________________

Testing

for start tests -
make clean
make test
_____________________________________________________________________________________________________________
