#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    if(!s21_check_matrix(A)||!s21_check_matrix(B)) return INCORRECT_MATRIX;

    if(!result || A->columns != B->rows) return CALCULATION_ERROR;

   int err = s21_create_matrix(A->rows, B->columns, result);
   if(err != OK) return err;

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