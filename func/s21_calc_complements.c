#include "../s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка входных данных
    if (A == NULL || A->matrix == NULL || result == NULL) {
        return INCORRECT_MATRIX;
    }
    if (A->rows != A->columns || A->rows < 1) {
        return CALCULATION_ERROR;
    }

    // Создаем результирующую матрицу
    int status = s21_create_matrix(A->rows, A->columns, result);
    if (status != OK) return status;

    // Особый случай для матрицы 1×1
    if (A->rows == 1) {
        result->matrix[0][0] = 1.0;
        return OK;
    }

    // Вычисляем алгебраические дополнения
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            // Создаем минор
            matrix_t minor = {0};
            status = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
            if (status != OK) {
                s21_remove_matrix(result);
                return status;
            }

            // Заполняем минор (исключаем i-ю строку и j-й столбец)
            for (int mi = 0, ai = 0; ai < A->rows; ai++) {
                if (ai == i) continue;
                for (int mj = 0, aj = 0; aj < A->columns; aj++) {
                    if (aj == j) continue;
                    minor.matrix[mi][mj++] = A->matrix[ai][aj];
                }
                mi++;
            }

            // Вычисляем определитель минора
            double det = 0.0;
            status = s21_determinant(&minor, &det);
            s21_remove_matrix(&minor);
            if (status != OK) {
                s21_remove_matrix(result);
                return status;
            }

            // Вычисляем алгебраическое дополнение
            result->matrix[i][j] = ((i + j) % 2 ? -det : det);
        }
    }
    
    return OK;
}