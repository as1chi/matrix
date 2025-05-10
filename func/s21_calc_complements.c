#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    if (A == NULL || A->matrix == NULL || result == NULL) {
        return INCORRECT_MATRIX;
    }

    if (A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
        return INCORRECT_MATRIX;
    }

    if (result->matrix != NULL) {
        s21_remove_matrix(result);
    }

    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
        return INCORRECT_MATRIX;
    }

    if (A->rows == 1 && A->columns == 1) {
        result->matrix[0][0] = 1.0;
        return OK;
    }

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            matrix_t minor_matrix;
            if (s21_get_minor(A, i, j, &minor_matrix) != OK) {
                s21_remove_matrix(result);
                return INCORRECT_MATRIX;
            }
            double det = 0.0;
            if (s21_determinant(&minor_matrix, &det) != OK) {
                s21_remove_matrix(&minor_matrix);
                s21_remove_matrix(result);
                return INCORRECT_MATRIX;
            }
            result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det;
            s21_remove_matrix(&minor_matrix);
        }
    }
    return OK;
}