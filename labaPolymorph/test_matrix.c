#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "complex.h"
#include "vendor/unity/src/unity.h"
#include <string.h>
#include <math.h>

void setUp(void) {}
void tearDown(void) {}

// ===================== Integer Matrix Tests (10) =====================
void test_int_addition_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    int a_data[4] = { 1, 2, 3, 4 };
    int b_data[4] = { 5, 6, 7, 8 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(6, res[0]);
    TEST_ASSERT_EQUAL(8, res[1]);
    TEST_ASSERT_EQUAL(10, res[2]);
    TEST_ASSERT_EQUAL(12, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_addition_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    int a_data[4] = { 10, 20, 30, 40 };
    int b_data[4] = { 1, 2, 3, 4 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(11, res[0]);
    TEST_ASSERT_EQUAL(22, res[1]);
    TEST_ASSERT_EQUAL(33, res[2]);
    TEST_ASSERT_EQUAL(44, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_addition_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    int a_data[4] = { 0, 0, 0, 0 };
    int b_data[4] = { 100, 200, 300, 400 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(100, res[0]);
    TEST_ASSERT_EQUAL(200, res[1]);
    TEST_ASSERT_EQUAL(300, res[2]);
    TEST_ASSERT_EQUAL(400, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_multiplication_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    int a_data[4] = { 1, 2, 3, 4 };
    int b_data[4] = { 5, 6, 7, 8 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(19, res[0]);
    TEST_ASSERT_EQUAL(22, res[1]);
    TEST_ASSERT_EQUAL(43, res[2]);
    TEST_ASSERT_EQUAL(50, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_multiplication_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 3, type, &A);
    createNewMatrix(3, 2, type, &B);

    int a_data[6] = { 1, 2, 3, 4, 5, 6 };
    int b_data[6] = { 7, 8, 9, 10, 11, 12 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(58, res[0]);
    TEST_ASSERT_EQUAL(64, res[1]);
    TEST_ASSERT_EQUAL(139, res[2]);
    TEST_ASSERT_EQUAL(154, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_multiplication_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(1, 3, type, &A);
    createNewMatrix(3, 1, type, &B);

    int a_data[3] = { 10, 20, 30 };
    int b_data[3] = { 1, 2, 3 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(140, res[0]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_transpose_1(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 3, type, &A);

    int data[6] = { 1, 2, 3, 4, 5, 6 };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    int* res = (int*)A.data;
    TEST_ASSERT_EQUAL(1, res[0]);
    TEST_ASSERT_EQUAL(4, res[1]);
    TEST_ASSERT_EQUAL(2, res[2]);
    TEST_ASSERT_EQUAL(5, res[3]);
    TEST_ASSERT_EQUAL(3, res[4]);
    TEST_ASSERT_EQUAL(6, res[5]);

    removeInternal(&A);
}

void test_int_transpose_2(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(1, 4, type, &A);

    int data[4] = { 10, 20, 30, 40 };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    int* res = (int*)A.data;
    TEST_ASSERT_EQUAL(10, res[0]);
    TEST_ASSERT_EQUAL(20, res[1]);
    TEST_ASSERT_EQUAL(30, res[2]);
    TEST_ASSERT_EQUAL(40, res[3]);

    removeInternal(&A);
}

void test_int_identity(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(3, 3, type, &A);
    createNewMatrix(3, 3, type, &B);

    int a_data[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
    int b_data[9] = { 5, 6, 7, 8, 9, 10, 11, 12, 13 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(5, res[0]);
    TEST_ASSERT_EQUAL(6, res[1]);
    TEST_ASSERT_EQUAL(7, res[2]);
    TEST_ASSERT_EQUAL(8, res[3]);
    TEST_ASSERT_EQUAL(9, res[4]);
    TEST_ASSERT_EQUAL(10, res[5]);
    TEST_ASSERT_EQUAL(11, res[6]);
    TEST_ASSERT_EQUAL(12, res[7]);
    TEST_ASSERT_EQUAL(13, res[8]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_int_zero_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    int a_data[4] = { 0, 0, 0, 0 };
    int b_data[4] = { 5, 6, 7, 8 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    int* res = (int*)result.data;
    TEST_ASSERT_EQUAL(5, res[0]);
    TEST_ASSERT_EQUAL(6, res[1]);
    TEST_ASSERT_EQUAL(7, res[2]);
    TEST_ASSERT_EQUAL(8, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

// ===================== Double Matrix Tests (10) =====================
void test_double_addition_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    double a_data[4] = { 1.5, 2.5, 3.5, 4.5 };
    double b_data[4] = { 0.5, 1.5, 2.5, 3.5 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.0, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.0, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.0, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 8.0, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_addition_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    double a_data[4] = { 0.1, 0.2, 0.3, 0.4 };
    double b_data[4] = { 0.01, 0.02, 0.03, 0.04 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.11, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.22, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.33, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.44, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_addition_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    double a_data[4] = { -1.1, -2.2, -3.3, -4.4 };
    double b_data[4] = { 1.1, 2.2, 3.3, 4.4 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_multiplication_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    double a_data[4] = { 1.0, 2.0, 3.0, 4.0 };
    double b_data[4] = { 5.0, 6.0, 7.0, 8.0 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 19.0, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 22.0, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 43.0, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 50.0, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_multiplication_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 3, type, &A);
    createNewMatrix(3, 2, type, &B);

    double a_data[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    double b_data[6] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.42, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.08, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.39, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 7.04, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_multiplication_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(1, 3, type, &A);
    createNewMatrix(3, 1, type, &B);

    double a_data[3] = { 1.5, 2.5, 3.5 };
    double b_data[3] = { 4.0, 5.0, 6.0 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 39.5, res[0]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_transpose_1(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 3, type, &A);

    double data[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    double* res = (double*)A.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.1, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.4, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.2, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.5, res[3]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.3, res[4]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.6, res[5]);

    removeInternal(&A);
}

void test_double_transpose_2(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(1, 4, type, &A);

    double data[4] = { 0.5, 1.5, 2.5, 3.5 };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    double* res = (double*)A.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.5, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.5, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.5, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.5, res[3]);

    removeInternal(&A);
}

void test_double_identity(void) {                                   //E matrix * B matrix
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(3, 3, type, &A);
    createNewMatrix(3, 3, type, &B);

    double a_data[9] = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };
    double b_data[9] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.1, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.2, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.3, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.4, res[3]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.5, res[4]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.6, res[5]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 7.7, res[6]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 8.8, res[7]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 9.9, res[8]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_zero_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    double a_data[4] = { 0.0, 0.0, 0.0, 0.0 };
    double b_data[4] = { 1.1, 2.2, 3.3, 4.4 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    double* res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2]);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

// ===================== Complex Matrix Tests (10) =====================
void test_complex_addition_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    struct { double real; double imag; } a_data[4] = {
        {1.0, 2.0}, {3.0, 4.0},
        {5.0, 6.0}, {7.0, 8.0}
    };
    struct { double real; double imag; } b_data[4] = {
        {0.5, 1.5}, {2.5, 3.5},
        {4.5, 5.5}, {6.5, 7.5}
    };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.5, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.5, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.5, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 7.5, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 9.5, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 11.5, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 13.5, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 15.5, res[3].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_addition_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(1, 2, type, &A);
    createNewMatrix(1, 2, type, &B);

    struct { double real; double imag; } a_data[2] = { {1.1, 2.2}, {3.3, 4.4} };
    struct { double real; double imag; } b_data[2] = { {0.1, 0.2}, {0.3, 0.4} };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.2, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.4, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.6, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.8, res[1].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_addition_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    struct { double real; double imag; } a_data[4] = {
        {-1.0, -2.0}, {-3.0, -4.0},
        {-5.0, -6.0}, {-7.0, -8.0}
    };
    struct { double real; double imag; } b_data[4] = {
        {1.0, 2.0}, {3.0, 4.0},
        {5.0, 6.0}, {7.0, 8.0}
    };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_multiplication_1(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(1, 2, type, &A);
    createNewMatrix(2, 1, type, &B);

    struct { double real; double imag; } a_data[2] = { {1.0, 2.0}, {3.0, 4.0} };
    struct { double real; double imag; } b_data[2] = { {5.0, 6.0}, {7.0, 8.0} };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -18.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 68.0, res[0].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_multiplication_2(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    struct { double real; double imag; } a_data[4] = {
        {1.1, 2.2}, {3.3, 4.4},
        {5.5, 6.6}, {7.7, 8.8}
    };
    struct { double real; double imag; } b_data[4] = {
        {0.1, 0.2}, {0.3, 0.4},
        {0.5, 0.6}, {0.7, 0.8}
    };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -1.32, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.62, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -1.76, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.82, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -2.2, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 10.78, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, -2.64, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 16.5, res[3].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_multiplication_3(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(1, 3, type, &A);
    createNewMatrix(3, 1, type, &B);

    struct { double real; double imag; } a_data[3] = { {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0} };
    struct { double real; double imag; } b_data[3] = { {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0} };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.0, res[0].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_transpose_1(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(2, 2, type, &A);

    struct { double real; double imag; } data[4] = {
        {1.1, 2.2}, {3.3, 4.4},
        {5.5, 6.6}, {7.7, 8.8}
    };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    struct { double real; double imag; } *res = A.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.1, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.2, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.5, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.6, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.3, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.4, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 7.7, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 8.8, res[3].imag);

    removeInternal(&A);
}

void test_complex_transpose_2(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(1, 3, type, &A);

    struct { double real; double imag; } data[3] = {
        {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}
    };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));

    struct { double real; double imag; } *res = A.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.0, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.0, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.0, res[2].imag);

    removeInternal(&A);
}

void test_complex_identity(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();
    createNewMatrix(3, 3, type, &A);
    createNewMatrix(3, 3, type, &B);

    struct { double real; double imag; } a_data[9] = {
        {1.0, 0.0}, {0.0, 0.0}, {0.0, 0.0},
        {0.0, 0.0}, {1.0, 0.0}, {0.0, 0.0},
        {0.0, 0.0}, {0.0, 0.0}, {1.0, 0.0}
    };
    struct { double real; double imag; } b_data[9] = {
        {1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6},
        {7.7, 8.8}, {9.9, 10.1}, {11.1, 12.2},
        {13.3, 14.4}, {15.5, 16.6}, {17.7, 18.8}
    };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 1.1, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 2.2, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 3.3, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 4.4, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 5.5, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 6.6, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 7.7, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 8.8, res[3].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 9.9, res[4].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 10.1, res[4].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 11.1, res[5].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 12.2, res[5].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 13.3, res[6].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 14.4, res[6].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 15.5, res[7].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 16.6, res[7].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 17.7, res[8].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 18.8, res[8].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_zero_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    createNewMatrix(2, 2, type, &A);
    createNewMatrix(2, 2, type, &B);

    struct { double real; double imag; } a_data[4] = {
        {0.0, 0.0}, {0.0, 0.0},
        {0.0, 0.0}, {0.0, 0.0}
    };
    struct { double real; double imag; } b_data[4] = {
        {1.1, 2.2}, {3.3, 4.4},
        {5.5, 6.6}, {7.7, 8.8}
    };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));

    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[0].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[1].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[2].imag);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3].real);
    TEST_ASSERT_FLOAT_WITHIN(1e-9, 0.0, res[3].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

// ===================== Main Test Runner =====================
int main(void) {
    UNITY_BEGIN();

    // Integer matrix tests (10)
    RUN_TEST(test_int_addition_1);
    RUN_TEST(test_int_addition_2);
    RUN_TEST(test_int_addition_3);
    RUN_TEST(test_int_multiplication_1);
    RUN_TEST(test_int_multiplication_2);
    RUN_TEST(test_int_multiplication_3);
    RUN_TEST(test_int_transpose_1);
    RUN_TEST(test_int_transpose_2);
    RUN_TEST(test_int_identity);
    RUN_TEST(test_int_zero_matrix);

    // Double matrix tests (10)
    RUN_TEST(test_double_addition_1);
    RUN_TEST(test_double_addition_2);
    RUN_TEST(test_double_addition_3);
    RUN_TEST(test_double_multiplication_1);
    RUN_TEST(test_double_multiplication_2);
    RUN_TEST(test_double_multiplication_3);
    RUN_TEST(test_double_transpose_1);
    RUN_TEST(test_double_transpose_2);
    RUN_TEST(test_double_identity);
    RUN_TEST(test_double_zero_matrix);

    // Complex matrix tests (10)
    RUN_TEST(test_complex_addition_1);
    RUN_TEST(test_complex_addition_2);
    RUN_TEST(test_complex_addition_3);
    RUN_TEST(test_complex_multiplication_1);
    RUN_TEST(test_complex_multiplication_2);
    RUN_TEST(test_complex_multiplication_3);
    RUN_TEST(test_complex_transpose_1);
    RUN_TEST(test_complex_transpose_2);
    RUN_TEST(test_complex_identity);
    RUN_TEST(test_complex_zero_matrix);

    return UNITY_END();
}

