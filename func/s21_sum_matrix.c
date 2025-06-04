#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = s21_check_binary_operation(A, B, result);
    if (status != OK) return status;
    
    status = s21_create_matrix(A->rows, A->columns, result);
    if (status != OK) return status;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }
    return OK;
}