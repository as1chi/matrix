#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Проверка входных параметров
    if (A == NULL || A->matrix == NULL || result == NULL) {
        return INCORRECT_MATRIX;
    }

    // Проверка квадратности матрицы
    if (A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
        return CALCULATION_ERROR;
    }

    // Инициализация структуры результата
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;

    // Создание матрицы для результата
    if (s21_create_matrix(A->rows, A->columns, result) != OK) {
        return INCORRECT_MATRIX;
    }

    // Особый случай для матрицы 1x1
    if (A->rows == 1) {
        result->matrix[0][0] = 1.0;
        return OK;
    }

    int status = OK;
    
    for (int i = 0; i < A->rows && status == OK; i++) {
        for (int j = 0; j < A->columns && status == OK; j++) {
            matrix_t minor_matrix = {0};
            
            status = s21_get_minor(A, i, j, &minor_matrix);
            if (status != OK) break;
            
            double det = 0.0;
            status = s21_determinant(&minor_matrix, &det);
            
            result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * det;
            s21_remove_matrix(&minor_matrix);
        }
    }

    // Если была ошибка - очищаем результат
    if (status != OK) {
        s21_remove_matrix(result);
    }

    return status;
}