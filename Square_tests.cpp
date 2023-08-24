#include "Square_types.h"
#include "Square_tests.h"
#include "Square_solver.h"
#include <assert.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>

int TestOne(const struct SquareTrinomial *coeffs, struct Roots *roots, const struct Roots *refroots) {

    assert(coeffs != NULL);
    assert(roots != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    square_solver(coeffs, roots);

    if (!f_comparison(roots->x1, refroots->x1) || !f_comparison(roots->x2, refroots->x2) || roots->count_solutions != refroots->count_solutions) {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        printf("Failed: x1 = %lf, x2 = %lf, count_solutions = %d\n"
               "Expected: x1 = %lf, x2 = %lf, count_solutions = %d\n", roots->x1, roots->x2, roots->count_solutions,
                refroots->x1, refroots->x2, refroots->count_solutions);

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        return 0;
    }
    else {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Test OK.\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return 1;
    }
}


int TestAll(void) {

    #define CREAT_TEST TestOne(&tests_coeffs[i], &roots, &tests_refroots[i])

    int count_correct_tests = 0;

    struct SquareTrinomial tests_coeffs[] = {{1, 2, 1},
                                             {2, 2, -4},
                                             {0, 0, 0},
                                             {0, 0, 6},
                                             {0, 2, -4},
                                             {1, 0, -4}};
    struct Roots tests_refroots[] = {{-1, -1, 1},
                                    {1, -2, 2},
                                    {0, 0, INFINITE_SOLUTIONS},
                                    {0, 0, 0},
                                    {2, 2, 1},
                                    {2, -2, 2}};

    for(int i = 0; i < N_TESTS; i++) {

        struct Roots roots;

        count_correct_tests += CREAT_TEST;
    }

    #undef CREAT_TEST

    return count_correct_tests;
}


void test_question(void) {
    printf("Хотите ли вы проверить работу программы?\nВведите 1,"
           " если хотите, и что угодно, если вы доверяете программе.\n");
    int answer = 0;
    scanf("%d", &answer);
    if (answer == 1) {

        printf("Количество правильных тестов: %d\n"
           "Количество пройденных тестов: %d\n", TestAll(), N_TESTS);
    }
    else clear_buf();
}
