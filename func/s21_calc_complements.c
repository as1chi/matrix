#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result){
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

    if(A->rows == 1){
        result->matrix[0][0] = 1.0;
    }

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; i < A->columns; j++){
            matrix_t minor_matrix;
            if(s21_create_matrix(A, i, j, &minor_matrix) != OK){
                return INCORRECT_MATRIX;
            }
            double det = 0.0;
            if(s21_determinant(&minor_matrix, &det) != OK){
                return INCORRECT_MATRIX;
                s21_remove_matrix(&minor_matrix);
            }
            result->matrix[i][j] = pow(-1, i+j)*det;
            s21_remove_matrix(&minor_matrix);
        }
    }
    return OK;
}