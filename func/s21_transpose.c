#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result){
    if (A == NULL || A->matrix == NULL) {
        return  INCORRECT_MATRIX;
    }

    if (A->rows < 1 || A->columns < 1) {
        return INCORRECT_MATRIX;
    }

    if(result->matrix != NULL){
        s21_remove_matrix(result);
    }
    
    if (s21_create_matrix(A->rows, A->columns, result) != OK){
        return INCORRECT_MATRIX;
    }

    for (int i = 0; i < A->rows; i++){
        for (int j = 0; j < A->columns; j++){
            result->matrix[j][i] = A->matrix[i][j];
        }
    }
}