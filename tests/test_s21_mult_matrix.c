#include "./test_main.h"

START_TEST(test_mult_matrix_int_values) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  double a_vals[] = {1, 2, 3, 4};
  double b_vals[] = {5, 6, 7, 8};
  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  int code = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(code, OK);

  double expected[] = {19, 22, 43, 50};
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_matrix_double_values) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  double a_vals[] = {1.5, 2.5, 3.1, 4.2};
  double b_vals[] = {5.0, 6.0, 7.0, 8.0};
  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  int code = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(code, OK);

  double expected[] = {1.5 * 5 + 2.5 * 7, 1.5 * 6 + 2.5 * 8, 3.1 * 5 + 4.2 * 7,
                       3.1 * 6 + 4.2 * 8};
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_mult_matrix_incompatible_sizes) {
  matrix_t A, B, C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_matrix_invalid) {
  matrix_t A = {0}, B = {0}, C;
  int code = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_visual_example) {
  matrix_t A, B, C;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);

  double a_vals[] = {1, 4, 2, 5, 3, 6};

  double b_vals[] = {1, -1, 1, 2, 3, 4};

  double expected[] = {9, 11, 17, 12, 13, 22, 15, 15, 27};

  fill_matrix_from_array(&A, a_vals);
  fill_matrix_from_array(&B, b_vals);

  int code = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix_equals_array(&C, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *get_suite_s21_mult_matrix(void) {
  Suite *s = suite_create("Mult matrix");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_mult_matrix_int_values);
  tcase_add_test(tc, test_mult_matrix_double_values);
  tcase_add_test(tc, test_mult_matrix_incompatible_sizes);
  tcase_add_test(tc, test_mult_matrix_invalid);
  tcase_add_test(tc, test_visual_example);
  suite_add_tcase(s, tc);

  return s;
}
