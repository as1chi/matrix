#include "../s21_matrix.h"
int s21_check_matrix(const matrix_t *A){
    return (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0);
}