#pragma once

typedef enum ErrorCode {
    ERROR_NONE = 0,                    // Успешно
    ERROR_NULL_MATRIX,                 // Матрица NULL
    ERROR_NULL_DATA,                   // data = NULL
    ERROR_NULL_TYPEINFO,               // typeInfo = NULL
    ERROR_SIZE_MISMATCH,               // Размеры не совпадают
    ERROR_TYPE_MISMATCH,               // Типы не совпадают
    ERROR_INVALID_MULTIPLICATION,      // Несовместимые для умножения
    ERROR_NULL_SOURCE_ROWS,            // Массив строк NULL
    ERROR_SOURCE_ROW_OUT_OF_BOUNDS,    // Индекс строки вне диапазона
    ERROR_TARGET_ROW_OUT_OF_BOUNDS,    // Индекс целевой строки вне диапазона
    ERROR_SAME_SOURCE_AND_TARGET_ROW,  // Источник совпадает с целью
    ERROR_SOURCE_ROW_COUNT_ZERO,       // Количество строк ноль
    ERROR_UNKNOWN                      // Неизвестная ошибка
} ErrorCode;
