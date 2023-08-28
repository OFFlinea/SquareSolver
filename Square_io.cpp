#include "Square_types.h"
#include "Square_io.h"
#include "Square_tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <math.h>

void introduction(void) {

    printf("Эта программа решает квадратное уравнение\n");
}


void help(void) {

    printf("\n\nКраткое описание работы программы:\n"
           "В начале вас спросят хотите ли вы протестировать программу. "
                            "Если да, то она протестируется, если нет - пойдёт дальше.\n"

           "Затем попросит ввести вас коэффициенты квадратного уравнения, "
                            "после ввода вам выведутся корни уравнения.\n"

           "-t Filename Включает тесты программы. В файле должны быть по порядку "
                            "сначала коэффициенты уравнения, затем корни и их количество.\n"

           "Бесконечное множество решений считается тройкой.\nЕсли корень один, то оба корня одинаковы.\n"
           "Если корня нет, он считается нулём.\n\n");
}


void command_check(int argc, char *argv[]) {

    bool is_test = false;

    for (int i = 0; i < argc; i++) {

        if (strcmp(argv[i], "-t") == 0) {

            test_file(argv[i + 1]);
            is_test = true;
        }

        else if (strcmp(argv[i], "--help") == 0) {

            help();
        }
    }

    if (!is_test) {

            test_question();
        }
}


void eof_control(const int c) {

    if (c == EOF) {

        printf("Зачем вы ввели EOF?\n"
               "Эта программа будет завершена.\n");

        exit(0);
    }
}


void clear_buf(void) {

    int c = getchar();

    while((c = getchar()) != '\n') {

        eof_control(c);
    }
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

        SetConsoleTextAttribute(hConsole, WHITE);
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
            printf("Корни уравнения: %.*lf %.*lf\n", DIGITS_AFTER_POINT, roots->x1,
                    DIGITS_AFTER_POINT, roots->x2);
            break;
        default:
            printf("Бесконечное множество решений.");
            break;
    }
}
