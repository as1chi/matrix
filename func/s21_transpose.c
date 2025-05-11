#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    if(!s21_check_matrix(A)){
        return INCORRECT_MATRIX;
    }
    if(!result){
        return CALCULATION_ERROR;
    }

    int err = s21_create_matrix(A->columns, A->rows, result);
    if(err != OK) return err;

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < A->columns; j++){
            result->matrix[j][i] = A->matrix[i][j];
        }
    }

    return OK;
}