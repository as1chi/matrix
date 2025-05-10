#include "./test_main.h"

START_TEST(test_complements_1x1) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_3x3) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  double expected[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  ck_assert_int_eq(matrix_equals_array(&result, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_zero_matrix) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) A.matrix[i][j] = 0;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  double expected[] = {0, 0, 0, 0};
  ck_assert_int_eq(matrix_equals_array(&result, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_invalid_matrix) {
  matrix_t A = {NULL, 3, 3};
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_complements_non_square) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_complements_from_image_example) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);

  double expected[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_int_eq(matrix_equals_array(&result, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *get_suite_s21_calc_complements(void) {
  Suite *s = suite_create("Calc Complements");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_complements_1x1);
  tcase_add_test(tc, test_complements_3x3);
  tcase_add_test(tc, test_complements_zero_matrix);
  tcase_add_test(tc, test_complements_invalid_matrix);
  tcase_add_test(tc, test_complements_non_square);
  tcase_add_test(tc, test_complements_from_image_example);

  suite_add_tcase(s, tc);
  return s;
}
