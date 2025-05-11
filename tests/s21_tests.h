#ifndef SRC_TEST_MATRIX_H
#define SRC_TEST_MATRIX_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

void s21_init_matrix(double number, matrix_t *A);
Suite *create_remove_suite(void);
Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_suite(void);
Suite *determinant_suite(void);
Suite *calc_complements_suite(void);
Suite *inverse_matrix_suite(void);

#endif