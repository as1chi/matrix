#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
    int status = s21_check_square_matrix(A);
    if (status != OK) return status;
    if (result == NULL) return INCORRECT_MATRIX;

    double det = 0.0;
    if (s21_determinant(A, &det) != OK) return CALCULATION_ERROR;
    if (fabs(det) < EPS) return CALCULATION_ERROR;
  
    if (A->rows == 1) {
        if (s21_create_matrix(1, 1, result) != OK) return CALCULATION_ERROR;
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
        return OK;
    }

    matrix_t complements, transposed;
    status = s21_calc_complements(A, &complements);
    if (status != OK) return status;

    status = s21_transpose(&complements, &transposed);
    s21_remove_matrix(&complements);
    if (status != OK) return status;

    status = s21_mult_number(&transposed, 1.0 / det, result);
    s21_remove_matrix(&transposed);
    return status;
}
