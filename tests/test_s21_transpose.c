#include "./test_main.h"

START_TEST(test_transpose_rectangular_2x3) {
  matrix_t A, B;
  s21_create_matrix(2, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6};
  fill_matrix_from_array(&A, values);

  int code = s21_transpose(&A, &B);
  ck_assert_int_eq(code, OK);

  double expected[] = {1, 4, 2, 5, 3, 6};
  ck_assert_int_eq(matrix_equals_array(&B, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transpose_square_2x2) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);

  double values[] = {1, 2, 3, 4};
  fill_matrix_from_array(&A, values);

  int code = s21_transpose(&A, &B);
  ck_assert_int_eq(code, OK);

  double expected[] = {1, 3, 2, 4};
  ck_assert_int_eq(matrix_equals_array(&B, expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transpose_1x1) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42;

  int code = s21_transpose(&A, &B);
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq(B.matrix[0][0], 42);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transpose_invalid_matrix) {
  matrix_t A = {0};
  matrix_t B;
  int code = s21_transpose(&A, &B);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_transpose_null_result) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  int code = s21_transpose(&A, NULL);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *get_suite_s21_transpose(void) {
  Suite *s = suite_create("Transpose");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_transpose_rectangular_2x3);
  tcase_add_test(tc, test_transpose_square_2x2);
  tcase_add_test(tc, test_transpose_1x1);
  tcase_add_test(tc, test_transpose_invalid_matrix);
  tcase_add_test(tc, test_transpose_null_result);
  suite_add_tcase(s, tc);

  return s;
}
