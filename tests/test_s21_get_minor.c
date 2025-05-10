#include "./test_main.h"

START_TEST(test_get_minor_0_0) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 0, 0, &minor), OK);

  double expected[] = {5, 6, 8, 9};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_0_1) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 0, 1, &minor), OK);

  double expected[] = {4, 6, 7, 9};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_0_2) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 0, 2, &minor), OK);

  double expected[] = {4, 5, 7, 8};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_1_0) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 1, 0, &minor), OK);

  double expected[] = {2, 3, 8, 9};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_1_1) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 1, 1, &minor), OK);

  double expected[] = {1, 3, 7, 9};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_1_2) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 1, 2, &minor), OK);

  double expected[] = {1, 2, 7, 8};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_2_0) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 2, 0, &minor), OK);

  double expected[] = {2, 3, 5, 6};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_2_1) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 2, 1, &minor), OK);

  double expected[] = {1, 3, 4, 6};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_2_2) {
  matrix_t A, minor;
  s21_create_matrix(3, 3, &A);

  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  fill_matrix_from_array(&A, values);

  ck_assert_int_eq(s21_get_minor(&A, 2, 2, &minor), OK);

  double expected[] = {1, 2, 4, 5};

  ck_assert_int_eq(minor.rows, 2);
  ck_assert_int_eq(minor.columns, 2);
  ck_assert_int_eq(matrix_equals_array(&minor, expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&minor);
}
END_TEST

START_TEST(test_get_minor_invalid_matrix) {
  matrix_t A = {NULL, 3, 3};
  matrix_t minor;
  ck_assert_int_eq(s21_get_minor(&A, 0, 0, &minor), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_get_minor_out_of_bounds) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  matrix_t minor;
  ck_assert_int_eq(s21_get_minor(&A, 2, 0, &minor), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_get_minor(&A, 0, 2, &minor), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *get_suite_s21_get_minor(void) {
  Suite *s = suite_create("Get minor");

  TCase *tc = tcase_create("Core");
  tcase_add_test(tc, test_get_minor_0_0);
  tcase_add_test(tc, test_get_minor_0_1);
  tcase_add_test(tc, test_get_minor_0_2);
  tcase_add_test(tc, test_get_minor_1_0);
  tcase_add_test(tc, test_get_minor_1_1);
  tcase_add_test(tc, test_get_minor_1_2);
  tcase_add_test(tc, test_get_minor_2_0);
  tcase_add_test(tc, test_get_minor_2_1);
  tcase_add_test(tc, test_get_minor_2_2);

  tcase_add_test(tc, test_get_minor_invalid_matrix);
  tcase_add_test(tc, test_get_minor_out_of_bounds);

  suite_add_tcase(s, tc);
  return s;
}
