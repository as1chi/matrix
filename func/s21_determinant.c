#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result){
      if (A == NULL || A->matrix == NULL || result == NULL) {
        return  INCORRECT_MATRIX;
    }

  if(A->rows != A->columns || A->rows < 1){
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

    *result = 0;
    int status = OK;
    
    for(int i = 0; i<A->rows && status == OK;i++){
        matrix_t *minor_matrix;

        if(s21_create_matrix(A->rows-1,A->rows-1,&minor_matrix) == OK){
            for(int j = 1;j<A->rows;j++){
                for(int k= 0, m = 0;k<A->columns;k++){
                    if(k == 0) continue;
                    minor_matrix->matrix[j-1][m] = A->matrix[j][k];
                }
            }
            double det = 0;
            if((status = s21_determinant(minor_matrix,&det))==OK){
                *result += pow(-1,i)*A->matrix[0][i]*det;
            }
            s21_remove_matrix(&minor_matrix);
        }
    }
    return status;
    }
