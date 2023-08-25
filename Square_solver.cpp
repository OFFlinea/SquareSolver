#include "Square_types.h"
#include "Square_solver.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>


bool is_zero(double n) {

    assert(isfinite(n));

    return fabs(n) < EPSILON;

}


bool is_greater(double n) {

    assert(isfinite(n));

    return n > EPSILON;
}


bool f_comparison(double x, double y) {

    assert(isfinite(x));
    assert(isfinite(y));

    return fabs(x - y) < EPSILON;
}


void linear_solver(const struct SquareTrinomial *coeffs, struct Roots *roots) {

    assert(coeffs != NULL);
    assert(roots  != NULL);

    if (!is_zero(coeffs->b)) {

        roots->x1 = -coeffs->c / coeffs->b;
        roots->x2 = roots->x1;
        roots->count_solutions = 1;
    }
    else {
        roots->count_solutions = (is_zero(coeffs->c)) ? INFINITE_SOLUTIONS : 0;
    }
}


void square_solver(const struct SquareTrinomial *coeffs, struct Roots *roots) {

    assert(coeffs != NULL);
    assert(roots != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    *roots = {0, 0, -1};

    if (!is_zero(coeffs->a)) {

        const double d = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

        if (is_greater(d)) {

            const double d_sqrt = sqrt(d);
            roots->x1 = (-coeffs->b + d_sqrt) / (2 * coeffs->a);
            roots->x2 = (-coeffs->b - d_sqrt) / (2 * coeffs->a);
            roots->count_solutions = 2;
        }

        else if (is_zero(d)) {

            roots->x1 = -coeffs->b / (2 * coeffs->a);
            roots->x1 = (is_zero(roots->x1)) ? 0 : roots->x1;
            roots->x2 = roots->x1;
            roots->count_solutions = 1;
        }

        else {

            roots->count_solutions = 0;
        }
    }

    else
        linear_solver(coeffs, roots);

}
