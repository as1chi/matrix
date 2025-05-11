#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if(!s21_check_matrix(A)|| result == NULL){
        return INCORRECT_MATRIX;
    }

    if (A->rows != A->columns) {
        return CALCULATION_ERROR;
    }

    double det = 0.0;
    if (s21_determinant(A, &det) != OK) return CALCULATION_ERROR;
    if (fabs(det) < EPS) return CALCULATION_ERROR;
  
    if (A->rows == 1) {
      if (s21_create_matrix(1, 1, result) != OK) return CALCULATION_ERROR;
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
      return OK;
    }

    matrix_t complements, transposed;
  int err = s21_calc_complements(A, &complements);
  if (err != OK) return err;

  err = s21_transpose(&complements, &transposed);
  s21_remove_matrix(&complements);
  if (err != OK) return err;

  err = s21_mult_number(&transposed, 1.0 / det, result);
  s21_remove_matrix(&transposed);
  return err;
}
