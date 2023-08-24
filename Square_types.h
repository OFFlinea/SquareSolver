#ifndef SQUARE_TYPES_H
#define SQUARE_TYPES_H

const int N_TESTS = 6;
const int INFINITE_SOLUTIONS = 3;

struct SquareTrinomial
{
    double a;
    double b;
    double c;
};

struct Roots
{
    double x1;
    double x2;
    int count_solutions;
};

void clear_buf(void);

#endif

