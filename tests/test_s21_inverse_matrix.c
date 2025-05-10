#include "./test_main.h"

START_TEST(test_inverse_1x1) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2.0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.5, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_2x2_precise) {
  matrix_t A, expected, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &expected);

  double values[] = {4.000001, 7.000001, 2.000001, 6.000001};
  double inverse[] = {0.6, -0.7, -0.2, 0.4};
  fill_matrix_from_array(&A, values);
  fill_matrix_from_array(&expected, inverse);

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_3x3_image_example) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  double values[] = {1, 2, 3, 0, 1, 4, 5, 6, 0};
  double expected[] = {-24, 18, 5, 20, -15, -4, -5, 4, 1};

  fill_matrix_from_array(&A, values);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);

  // Умножаем на детерминант 1/1 = 1 => результат как есть
  ck_assert_int_eq(matrix_equals_array(&result, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_singular_matrix) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_not_square) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_null_matrix) {
  matrix_t *null_matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(null_matrix, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_inverse_from_image_example) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  double values[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};

  double expected[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};

  fill_matrix_from_array(&A, values);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(matrix_equals_array(&result, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *get_suite_s21_inverse_matrix(void) {
  Suite *s = suite_create("Inverse Matrix");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_inverse_1x1);
  tcase_add_test(tc, test_inverse_2x2_precise);
  tcase_add_test(tc, test_inverse_3x3_image_example);
  tcase_add_test(tc, test_inverse_singular_matrix);
  tcase_add_test(tc, test_inverse_not_square);
  tcase_add_test(tc, test_inverse_null_matrix);
  tcase_add_test(tc, test_inverse_from_image_example);

  suite_add_tcase(s, tc);
  return s;
}
