#include "./test_main.h"

// 1x1: простой случай
START_TEST(test_determinant_simple_1x1) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42.0;

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 42.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 2x2: точные double
START_TEST(test_determinant_simple_2x2) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  double values[] = {1.000001, 2.000001, 3.000001, 4.000001};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -2.000000, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 2x2: отрицательное значение
START_TEST(test_determinant_2x2_negative) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  double values[] = {3, 8, 4, 6};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -14.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 3x3: детерминант -306
START_TEST(test_determinant_3x3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double values[] = {6, 1, 1, 4, -2, 5, 2, 8, 7};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, -306, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 4x4
START_TEST(test_determinant_4x4) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  double values[] = {1, 0, 2, -1, 3, 0, 0, 5, 2, 1, 4, -3, 1, 0, 5, 0};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 30, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 5x5
START_TEST(test_determinant_5x5) {
  matrix_t A;
  s21_create_matrix(5, 5, &A);
  double values[] = {1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 0, 0, 1,
                     2, 3, 0, 0, 0, 1, 2, 0, 0, 0, 0, 1};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 1, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// 3x3: вырожденная
START_TEST(test_determinant_singular) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(result, 0.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

// Неквадратная
START_TEST(test_determinant_not_square) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);

  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

// rows = 0
START_TEST(test_determinant_zero_size) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
}
END_TEST

// NULL указатель на матрицу
START_TEST(test_determinant_null_matrix) {
  double result = 0;
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
}
END_TEST

// NULL указатель на result
START_TEST(test_determinant_null_result_ptr) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_determinant(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *get_suite_s21_determinant(void) {
  Suite *s = suite_create("Determinant");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_determinant_simple_1x1);
  tcase_add_test(tc, test_determinant_simple_2x2);
  tcase_add_test(tc, test_determinant_2x2_negative);
  tcase_add_test(tc, test_determinant_3x3);
  tcase_add_test(tc, test_determinant_4x4);
  tcase_add_test(tc, test_determinant_5x5);
  tcase_add_test(tc, test_determinant_singular);
  tcase_add_test(tc, test_determinant_not_square);
  tcase_add_test(tc, test_determinant_zero_size);
  tcase_add_test(tc, test_determinant_null_matrix);
  tcase_add_test(tc, test_determinant_null_result_ptr);

  suite_add_tcase(s, tc);
  return s;
}
