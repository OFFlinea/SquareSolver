#include "Square_types.h"
#include "Square_tests.h"
#include "Square_solver.h"
#include "Square_io.h"
#include <assert.h>
#include <windows.h>
#include <stdio.h>
#include <math.h>

int TestOne(const struct Test *tests_params, struct Roots *roots) {

    assert(tests_params != NULL);
    assert(roots != NULL);
    assert(isfinite(tests_params->a));
    assert(isfinite(tests_params->b));
    assert(isfinite(tests_params->c));
    assert(isfinite(tests_params->x1));
    assert(isfinite(tests_params->x2));

    struct SquareTrinomial coeffs = {tests_params->a, tests_params->b, tests_params->c};

    square_solver(&coeffs, roots);

    if (!f_comparison(roots->x1, tests_params->x1) ||
        !f_comparison(roots->x2, tests_params->x2) ||
        roots->count_solutions != tests_params->count_solutions) {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        printf("Failed:   x1 = %lf, x2 = %lf, count_solutions = %d\n"
               "Expected: x1 = %lf, x2 = %lf, count_solutions = %d\n", roots->x1, roots->x2,
                roots->count_solutions, tests_params->x1, tests_params->x2, tests_params->count_solutions);

        SetConsoleTextAttribute(hConsole, WHITE);

        return 0;
    }
    else {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Test OK.\n");
        SetConsoleTextAttribute(hConsole, WHITE);
        return 1;
    }
}


void TestAll(void) {

    #define CREAT_TEST TestOne(&tests_params[i], &roots)

    int count_correct_tests = 0;

    struct Test tests_params[] = {{1, 2,  1, -1, -1, 1},
                                  {2, 2, -4,  1, -2, 2},
                                  {0, 0,  0,  0,  0, INFINITE_SOLUTIONS},
                                  {0, 0,  6,  0,  0, 0},
                                  {0, 2, -4,  2,  2, 1},
                                  {1, 0, -4,  2, -2, 2},
                                  {2, 0,  0,  0,  0, 1}};

    const size_t N_TESTS = sizeof(tests_params) / sizeof(tests_params[0]);

    for(size_t i = 0; i < N_TESTS; i++) {

        struct Roots roots;

        count_correct_tests += CREAT_TEST;
    }

    #undef CREAT_TEST

    printf("Количество правильных тестов: %d\n"
               "Количество пройденных тестов: %d\n", count_correct_tests, N_TESTS);
}


int count_lines(const char filename[]) {

    FILE* file_test = fopen(filename, "r");

    int lines_count = 0;

    while (!feof(file_test)) {

        if (fgetc(file_test) == '\n')
            lines_count++;
    }

    fclose(file_test);
    return lines_count;
}


void test_question(void) {

    printf("Хотите ли вы проверить работу программы?\n"
           "Введите 1, если хотите, и что угодно, если вы доверяете программе.\n");

    int answer = 0;
    scanf("%d", &answer);

    if (answer == 1) {

        TestAll();
    }
    else {
        clear_buf();
    }
}


void test_file(const char filename[]) {

    FILE* file_tests = fopen(filename, "r");

    if (file_tests == NULL) {

        printf("После -t вы должны указывать файл с тестами, если вы сделали это, "
                                "значит ваш файл не в этой папке, программа не нашла его.\n");
        return;
    }

    const int NLINES = count_lines(filename);

    int correct_tests = 0;

    for (int i = 0; i < NLINES; i++) {

        struct Test tests_params = {};
        struct Roots roots = {};

        if (fscanf(file_tests, "%lf %lf %lf %lf %lf %d", &tests_params.a, &tests_params.b, &tests_params.c,
              &tests_params.x1, &tests_params.x2, &tests_params.count_solutions) != 6) {

            printf("Некорректный файл с тестами. Номер строки с некорректными данными: %d\n", i + 1);
            exit(0);
        }

        correct_tests += TestOne(&tests_params, &roots);
    }

    fclose(file_tests);

    printf("Количество правильных тестов: %d\n"
           "Количество пройденных тестов: %d\n", correct_tests, NLINES);

}
