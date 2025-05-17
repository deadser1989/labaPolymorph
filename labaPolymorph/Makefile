CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I. -Ivendor/unity/src
LDFLAGS = -lm

MATRIX_SRC = matrix.c integer.c double.c complex.c error.c input.c

TEST_SRC = test_matrix.c vendor/unity/src/unity.c

TEST_EXE = matrix_tests.exe

.PHONY: all test clean

all: test

test: $(MATRIX_SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_EXE) $^ $(LDFLAGS)
	.\$(TEST_EXE)

clean:
	del /Q /F $(TEST_EXE) *.o *.gcno *.gcda *.gcov coverage.info 2>nul
	if exist coverage_report rmdir /S /Q coverage_report 2>nul