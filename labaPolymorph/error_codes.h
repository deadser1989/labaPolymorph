#pragma once

typedef enum ErrorCode {
    ERROR_NONE = 0,                    // �������
    ERROR_NULL_MATRIX,                 // ������� NULL
    ERROR_NULL_DATA,                   // data = NULL
    ERROR_NULL_TYPEINFO,               // typeInfo = NULL
    ERROR_SIZE_MISMATCH,               // ������� �� ���������
    ERROR_TYPE_MISMATCH,               // ���� �� ���������
    ERROR_INVALID_MULTIPLICATION,      // ������������� ��� ���������
    ERROR_NULL_SOURCE_ROWS,            // ������ ����� NULL
    ERROR_SOURCE_ROW_OUT_OF_BOUNDS,    // ������ ������ ��� ���������
    ERROR_TARGET_ROW_OUT_OF_BOUNDS,    // ������ ������� ������ ��� ���������
    ERROR_SAME_SOURCE_AND_TARGET_ROW,  // �������� ��������� � �����
    ERROR_SOURCE_ROW_COUNT_ZERO,       // ���������� ����� ����
    ERROR_UNKNOWN                      // ����������� ������
} ErrorCode;
