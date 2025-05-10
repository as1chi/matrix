#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    if (A == NULL || A->matrix == NULL || result == NULL || A->rows < 1 || A->columns < 1) {
        return INCORRECT_MATRIX;
    }

    if (A->rows != A->columns) {
        return INCORRECT_MATRIX;
    }

    double det = 0.0;
    if (s21_determinant(A, &det) != OK) {
        return INCORRECT_MATRIX;
    }

    if (fabs(det) < EPS) {
        return CALCULATION_ERROR; 
    }

    if (result->matrix != NULL) {
        s21_remove_matrix(result);
    }
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
        return INCORRECT_MATRIX;
    }

    if (A->rows == 1) {
        if (fabs(A->matrix[0][0]) < EPS) {
            s21_remove_matrix(result);
            return CALCULATION_ERROR;
        }
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
        return OK;
    }

    matrix_t comp = {0}; 
    if (s21_calc_complements(A, &comp) != OK) {
        s21_remove_matrix(result);
        return INCORRECT_MATRIX;
    }

    matrix_t transpose = {0};
    if (s21_transpose(&comp, &transpose) != OK) {
        s21_remove_matrix(&comp);
        s21_remove_matrix(result);
        return INCORRECT_MATRIX;
    }

    if (s21_mult_number(&transpose, 1.0 / det, result) != OK) {
        s21_remove_matrix(&comp);
        s21_remove_matrix(&transpose);
        s21_remove_matrix(result);
        return INCORRECT_MATRIX;
    }

    s21_remove_matrix(&comp);
    s21_remove_matrix(&transpose);

    return OK;
}