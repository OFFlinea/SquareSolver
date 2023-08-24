#include <TXLib.h>
#include "Square_types.h"
#include "Square_io.h"
#include "Square_solver.h"
#include "Square_tests.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <assert.h>


int main() {

    introduction();
    test_question();

    struct Roots roots;
    struct SquareTrinomial coeffs;

    square_input(&coeffs);
    square_solver(&coeffs, &roots);
    square_print(&roots);

    return 0;
}
