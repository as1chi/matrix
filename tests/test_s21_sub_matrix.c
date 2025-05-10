#include "./test_main.h"

START_TEST(test_sub_basic) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  double a_vals[] = {5, 6, 7, 8};
  double b_vals[] = {1, 2, 3, 4};
  double expected[] = {4, 4, 4, 4};

  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix_equals_array(&result, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_double_precision) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  double a_vals[] = {1.123456, 2.234567, 3.345678, 4.456789};
  double b_vals[] = {0.123456, 1.234567, 2.345678, 3.456789};
  double expected[] = {1.123456 - 0.123456, 2.234567 - 1.234567,
                       3.345678 - 2.345678, 4.456789 - 3.456789};

  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix_equals_array(&result, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_diff_sizes) {
  matrix_t A, B, result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_invalid_matrix) {
  matrix_t A = {0}, B = {0}, result;
  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

Suite *get_suite_s21_sub_matrix(void) {
  Suite *s = suite_create("Sub matrix");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_sub_basic);
  tcase_add_test(tc, test_sub_double_precision);
  tcase_add_test(tc, test_sub_diff_sizes);
  tcase_add_test(tc, test_sub_invalid_matrix);
  suite_add_tcase(s, tc);

  return s;
}
