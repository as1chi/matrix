#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define INCORRECT_MATRIX 1

#define EPS 1e-7

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

#endif

