CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I. -Ivendor/unity/src
LDFLAGS = -lm

SRC = matrix.c integer.c double.c complex.c error.c input.c
TEST_SRC = test_matrix.c vendor/unity/src/unity.c

all: test

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) -o test.exe $^ $(LDFLAGS)
	.\test.exe

coverage: CFLAGS += -fprofile-arcs -ftest-coverage
coverage: test
	gcov -r matrix.c

clean:
	del /Q /F test.exe *.gcno *.gcda *.gcov coverage.info 2>nul
	if exist coverage_report rmdir /S /Q coverage_report 2>nul

.PHONY: all test coverage clean