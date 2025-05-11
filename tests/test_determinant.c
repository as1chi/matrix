#include "s21_tests.h"

START_TEST(s21_determinant_01) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_02) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  res = s21_determinant(&A, &determ);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_03) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_04) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 6;
  A.matrix[2][3] = 6;
  A.matrix[3][0] = -1;
  A.matrix[3][1] = 8;
  A.matrix[3][2] = 8;
  A.matrix[3][3] = 8;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 108);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_05) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_square_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 1, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_non_square_matrix) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_invalid_matrix) {
  double result = 0;
  int status = s21_determinant(NULL, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_determinant_zero_matrix) {
  matrix_t A;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_identity_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 1, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_diagonal_matrix_with_zeros) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_zero_matrix_2) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 0;
    }
  }

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_known_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -2;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 7;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, -306, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_random_values) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = -2;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 0;

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result, -34, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_invalid_size) {
  matrix_t A;
  s21_create_matrix(2, 3, &A);  // Not a square matrix

  double result = 0;
  int status = s21_determinant(&A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

// Функция для создания набора тестов для вычисления детерминанта матриц
Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\n\nTEST: s21_determinant");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_determinant_01);
  tcase_add_test(tc_core, s21_determinant_02);
  tcase_add_test(tc_core, s21_determinant_03);
  tcase_add_test(tc_core, s21_determinant_04);
  tcase_add_test(tc_core, s21_determinant_05);
  tcase_add_test(tc_core, test_determinant_square_matrix);
  tcase_add_test(tc_core, test_determinant_non_square_matrix);
  tcase_add_test(tc_core, test_determinant_invalid_matrix);
  tcase_add_test(tc_core, test_determinant_zero_matrix);
  tcase_add_test(tc_core, test_determinant_identity_matrix);
  tcase_add_test(tc_core, test_determinant_diagonal_matrix_with_zeros);
  tcase_add_test(tc_core, test_determinant_zero_matrix_2);
  tcase_add_test(tc_core, test_determinant_known_matrix);
  tcase_add_test(tc_core, test_determinant_random_values);
  tcase_add_test(tc_core, test_determinant_invalid_size);

  suite_add_tcase(s, tc_core);
  return s;
}