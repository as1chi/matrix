#include "../s21_matrix.h"

int s21_get_minor(matrix_t *A, int row, int col, matrix_t *result) {
       if (A == NULL || A->matrix == NULL) {
        return  INCORRECT_MATRIX;
    }

    if(row >= A->rows || col >= A->columns){
        return INCORRECT_MATRIX;
    }

    if (A->rows < 1 || A->columns < 1) {
        return INCORRECT_MATRIX;
    }
    
    if (s21_create_matrix(A->rows, A->columns, result) != OK){
        return INCORRECT_MATRIX;
    }

    if(s21_create_matrix(A->rows - 1, A->columns - 1, result) != OK){
        return INCORRECT_MATRIX;
    }

    for(int i = 0, ii = 0; i < A->rows; ++i){
        if(i == row){
            continue;
        }
        for(int j = 0, jj = 0; j < A->columns; ++j){
            if(j == col){
                continue;
            }
            result->matrix[ii][jj] = A->matrix[i][j];
        }
        ii++;
    } 
    return OK;
}