#include "./test_main.h"

START_TEST(test_mult_number_by_zero) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  double values[] = {1.123456, 2.234567, 3.345678, 4.456789};
  fill_matrix_from_array(&A, values);

  int code = s21_mult_number(&A, 0.0, &C);
  ck_assert_int_eq(code, OK);

  double expected[] = {0.0, 0.0, 0.0, 0.0};
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_number_by_one) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  double values[] = {1.111111, 2.222222, 3.333333, 4.444444};
  fill_matrix_from_array(&A, values);

  int code = s21_mult_number(&A, 1.0, &C);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix_equals_array(&C, values), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_number_by_positive_double) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  double values[] = {1.000001, 2.000002, 3.000003, 4.000004};
  fill_matrix_from_array(&A, values);

  double factor = 2.5;
  int code = s21_mult_number(&A, factor, &C);
  ck_assert_int_eq(code, OK);

  double expected[] = {1.000001 * factor, 2.000002 * factor, 3.000003 * factor,
                       4.000004 * factor};
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_number_by_negative_double) {
  matrix_t A, C;
  s21_create_matrix(2, 2, &A);
  double values[] = {1.123456, -2.654321, 3.789123, -4.321987};
  fill_matrix_from_array(&A, values);

  double factor = -1.5;
  int code = s21_mult_number(&A, factor, &C);
  ck_assert_int_eq(code, OK);

  double expected[] = {1.123456 * factor, -2.654321 * factor, 3.789123 * factor,
                       -4.321987 * factor};
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_number_invalid_matrix) {
  matrix_t A = {0}, C;
  int code = s21_mult_number(&A, 2.0, &C);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_mult_number_null_result) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_mult_number(&A, 1.0, NULL);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *get_suite_s21_mult_number(void) {
  Suite *s = suite_create("Mult number");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_mult_number_by_zero);
  tcase_add_test(tc, test_mult_number_by_one);
  tcase_add_test(tc, test_mult_number_by_positive_double);
  tcase_add_test(tc, test_mult_number_by_negative_double);
  tcase_add_test(tc, test_mult_number_invalid_matrix);
  tcase_add_test(tc, test_mult_number_null_result);
  suite_add_tcase(s, tc);

  return s;
}
