#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result){
    if(rows < 1 || columns < 1 || result == NULL) return INCORRECT_MATRIX;

    result->matrix = (double**)malloc(sizeof(double*)*rows);

    if(result->matrix == NULL) return INCORRECT_MATRIX;

    for(int i = 0; i < rows; i++){
        result->matrix[i] = (double*)malloc(sizeof(double)*columns);

        if(result->matrix[i] == NULL){
            for(int j = 0; j < i; j++){
                free(result->matrix[j]);
            }
            free(result->matrix);
            return INCORRECT_MATRIX;
    }
    
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result->matrix[i][j] = 0;
        }
    }
    result->rows = rows;
    result->columns = columns;

    return OK;
}