#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
     if (A == NULL || B == NULL || result == NULL || 
        A->matrix == NULL || B->matrix == NULL) {
        return INCORRECT_MATRIX;
    }

    // Проверка на некорректные размеры
    if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) {
        return INCORRECT_MATRIX;
    }

    // Проверка совместимости размеров матриц
    if (A->rows != B->rows || A->columns != B->columns) {
        return CALCULATION_ERROR;
    }

    // Инициализация результирующей матрицы
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
        return INCORRECT_MATRIX;
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for(int k = 0; k<A->columns;k++){
                result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
        }
        
    }

    
    return OK;
}