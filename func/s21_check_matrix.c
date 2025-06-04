#include "../s21_matrix.h"

// Функция проверки базовой валидности матрицы
int s21_check_matrix(const matrix_t *A) {
    return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0);
}

// Остальные функции остаются без изменений
int s21_check_binary_operation(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!s21_check_matrix(A) || !s21_check_matrix(B) || result == NULL) {
        return INCORRECT_MATRIX;
    }
    if (A->rows != B->rows || A->columns != B->columns) {
        return CALCULATION_ERROR;
    }
    return OK;
}

int s21_check_multiplication(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (!s21_check_matrix(A) || !s21_check_matrix(B) || result == NULL) {
        return INCORRECT_MATRIX;
    }
    if (A->columns != B->rows) {
        return CALCULATION_ERROR;
    }
    return OK;
}

int s21_check_square_matrix(matrix_t *A) {
    if (!s21_check_matrix(A)) {
        return INCORRECT_MATRIX;
    }
    if (A->rows != A->columns) {
        return CALCULATION_ERROR;
    }
    return OK;
}