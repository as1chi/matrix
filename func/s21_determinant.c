#include "../s21_matrix.h"

int s21_determinant(matrix_t* A, double* result) {
    int status = s21_check_square_matrix(A);
    if (status != OK) return status;
    if (result == NULL) return INCORRECT_MATRIX;

    // Базовые случаи
    if (A->rows == 1) {
        *result = A->matrix[0][0];
        return OK;
    }

    if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
        return OK;
    }

    *result = 0.0;
    status = OK;
    
    for (int col = 0; col < A->columns && status == OK; col++) {
        matrix_t minor;
        if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) != OK) {
            status = INCORRECT_MATRIX;
            break;
        }

        // Заполнение минора (исключаем 0 строку и col столбец)
        for (int i = 1, mi = 0; i < A->rows; i++, mi++) {
            for (int j = 0, mj = 0; j < A->columns; j++) {
                if (j == col) continue;
                minor.matrix[mi][mj++] = A->matrix[i][j];
            }
        }

        double minor_det = 0.0;
        status = s21_determinant(&minor, &minor_det);
        s21_remove_matrix(&minor);
        
        if (status != OK) break;
        
        *result += (col % 2 ? -1.0 : 1.0) * A->matrix[0][col] * minor_det;
    }
    
    return status;
}