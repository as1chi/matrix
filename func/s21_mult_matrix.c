#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = s21_check_multiplication(A, B, result);
    if (status != OK) return status;
    
    status = s21_create_matrix(A->rows, B->columns, result);
    if (status != OK) return status;

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
                result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
    }
    return OK;
}