#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

#define LIGHT_GREEN "\033[32;1m"
#define DARK_RED "\033[31;1m"
#define NOCOLOR "\033[0m"
#define YELLOW "\033[33;1m"

Suite *get_suite_s21_create_matrix(void);
Suite *get_suite_s21_remove_matrix(void);
Suite *get_suite_s21_eq_matrix(void);
Suite *get_suite_s21_transpose(void);
Suite *get_suite_s21_mult_matrix(void);
Suite *get_suite_s21_mult_number(void);
Suite *get_suite_s21_sub_matrix(void);
Suite *get_suite_s21_sum_matrix(void);
Suite *get_suite_s21_get_minor(void);
Suite *get_suite_s21_determinant(void);
Suite *get_suite_s21_calc_complements(void);
Suite *get_suite_s21_calc_complements(void);
Suite *get_suite_s21_inverse_matrix(void);

// Заполняем матрицу из массива
void fill_matrix_from_array(matrix_t *m, const double *values);
// Сравниваем матрицу с массивом
int matrix_equals_array(matrix_t *m, const double *values);
// Заполняем массив значениями по порядку
void fill_sequential(matrix_t *m);

#endif