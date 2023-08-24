#ifndef SQUARE_SOLVER
#define SQUARE_SOLVER

const double EPSILON = 1e-6;

bool is_zero(double n);

bool is_greater(double n);

bool f_comparison(double x, double y);

void square_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);

void linear_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);

#endif
