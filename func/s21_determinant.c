#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result){
      if (A == NULL || A->matrix == NULL) {
        return  INCORRECT_MATRIX;
    }

    if (A->rows < 1 || A->columns < 1) {
        return INCORRECT_MATRIX;
    }
    
    if (s21_create_matrix(A->rows, A->columns) != OK){
        return INCORRECT_MATRIX;
    }

    if(A->rows == 1){
        *result = A->matrix[0][0];
        return OK;
    }

    if(A->rows == 2){
        *result = A->matrix[0][0]*A->matrix[1][1] - A->matrix[0][1]*A->matrix[1][0];
        return OK;
    }

    for(int i = 0; i < A->rows; i++){
    }


    }
