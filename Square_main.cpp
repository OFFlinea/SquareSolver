#include <TXLib.h>
// #include "Square_io.h"
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <assert.h>

const int DIGITS_AFTER_POINT = 1;
const int N_TESTS = 6;
const int INFINITE_SOLUTIONS = 3;
const double EPSILON = 1e-6;

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

void test_question(void);

int TestOne(const struct SquareTrinomial *coeffs, struct Roots *roots, const struct Roots *refroots);

int TestAll(void);

bool is_zero(double n);

bool is_greater(double n);

bool f_comparison(double x, double y);

void square_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);

void linear_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);

void introduction(void);

void clear_buf(void);

void square_print(const struct Roots *roots);

void square_input(struct SquareTrinomial *coeffs);


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


bool is_zero(double n) {

    assert(isfinite(n));

    return (fabs(n) < EPSILON) ? true : false;

}


bool is_greater(double n) {

    assert(isfinite(n));

    return (n > EPSILON) ? true : false;
}


bool f_comparison(double x, double y) {

    assert(isfinite(x));
    assert(isfinite(y));

    return (fabs(x - y) < EPSILON) ? true : false;
}


void linear_solver(const struct SquareTrinomial *coeffs, struct Roots *roots) {

    assert(coeffs != NULL);
    assert(roots != NULL);

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
            roots->x2 = roots->x1;
            roots->count_solutions = 1;
        }

        else {

            roots->count_solutions = 0;
        }
    }

    else linear_solver(coeffs, roots);
}

void introduction(void) {

    printf("Эта программа решает квадратное уравнение\n");
}


void clear_buf(void) {

    int c = getchar();
    while((c = getchar()) != '\n');
}


void square_input(struct SquareTrinomial *coeffs) {

    assert(coeffs != NULL);
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    printf("Введите коэффициенты квадратного уравнения: ");

    while(scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c) != 3) {

        clear_buf();

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        printf("Вы ввели некорректные данные."
        " Вы должны ввести 3 числа через пробелы, попробуйте снова: ");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}


void square_print(const struct Roots *roots) {

    assert(roots != NULL);
    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    switch(roots->count_solutions) {

        case 0:
            printf("У данного уравнения нет корней в действительных величинах.\n");
            break;
        case 1:
            printf("Корень уравнения: %.*lf\n", DIGITS_AFTER_POINT, roots->x1);
            break;
        case 2:
            printf("Корни уравнения: %.*lf %.*lf\n", DIGITS_AFTER_POINT, roots->x1, DIGITS_AFTER_POINT, roots->x2);
            break;
        default:
            printf("Бесконечное множество решений.");
            break;
    }
}
