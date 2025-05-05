#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "complex.h"
#include "vendor/unity/src/unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_int_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoInteger();

    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 2, type, &A));
    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 2, type, &B));

    int a_data[4] = { 1, 2, 3, 4 };
    int b_data[4] = { 5, 6, 7, 8 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));
    int* add_res = (int*)result.data;
    TEST_ASSERT_EQUAL(6, add_res[0]);
    TEST_ASSERT_EQUAL(8, add_res[1]);
    removeInternal(&result);

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));
    int* mul_res = (int*)result.data;
    TEST_ASSERT_EQUAL(19, mul_res[0]);
    TEST_ASSERT_EQUAL(22, mul_res[1]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_double_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoDouble();

    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 2, type, &A));
    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 2, type, &B));

    double a_data[4] = { 1.0, 2.0, 3.0, 4.0 };
    double b_data[4] = { 5.0, 6.0, 7.0, 8.0 };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, addMatrix(&A, &B, &result));
    double* add_res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(0.001, 6.0, add_res[0]);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 8.0, add_res[1]);
    removeInternal(&result);

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));
    double* mul_res = (double*)result.data;
    TEST_ASSERT_FLOAT_WITHIN(0.001, 19.0, mul_res[0]);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 22.0, mul_res[1]);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_complex_matrix(void) {
    Matrix A, B, result;
    const TypeInfo* type = getTypeInfoComplex();

    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(1, 2, type, &A));
    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 1, type, &B));

    struct { double real; double imag; } a_data[2] = { {1.0, 2.0}, {3.0, 4.0} };
    struct { double real; double imag; } b_data[2] = { {5.0, 6.0}, {7.0, 8.0} };
    memcpy(A.data, a_data, sizeof(a_data));
    memcpy(B.data, b_data, sizeof(b_data));

    TEST_ASSERT_EQUAL(ERROR_NONE, multiplyMatrix(&A, &B, &result));
    struct { double real; double imag; } *res = result.data;
    TEST_ASSERT_FLOAT_WITHIN(0.001, -18.0, res[0].real);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 68.0, res[0].imag);

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void test_transpose(void) {
    Matrix A;
    const TypeInfo* type = getTypeInfoDouble();
    TEST_ASSERT_EQUAL(ERROR_NONE, createNewMatrix(2, 3, type, &A));

    double data[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    memcpy(A.data, data, sizeof(data));

    TEST_ASSERT_EQUAL(ERROR_NONE, transposeMatrix(&A));
    double* res = (double*)A.data;
    TEST_ASSERT_FLOAT_WITHIN(0.001, 1.1, res[0]);
    TEST_ASSERT_FLOAT_WITHIN(0.001, 4.4, res[1]);

    removeInternal(&A);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_int_matrix);
    RUN_TEST(test_double_matrix);
    RUN_TEST(test_complex_matrix);
    RUN_TEST(test_transpose);
    return UNITY_END();
}