#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
     if (A == NULL ||  result == NULL || 
        A->matrix == NULL ) {
        return INCORRECT_MATRIX;
    }

    // Проверка на некорректные размеры
    if (A->rows <= 0 || A->columns <= 0 ) {
        return INCORRECT_MATRIX;
    }

    // Инициализация результирующей матрицы
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
        return INCORRECT_MATRIX;
    }

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            result->matrix[i][j] = A->matrix[i][j]* number;
        }
    }
    return OK;
}