#include "Square_io.h"
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <math.h>

void introduction(void) {

    printf("��� ��������� ������ ���������� ���������\n");
}


void clear_buf(void) {

    int c = getchar();
    while((c = getchar()) != '\n');
}


void square_input(struct SquareTrinomial *coeffs) {

    printf("������� ������������ ����������� ���������: ");

    while(scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c) != 3) {

        clear_buf();

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        printf("�� ����� ������������ ������."
        " �� ������ ������ 3 ����� ����� �������, ���������� �����: ");

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}


void square_print(struct Roots *roots) {

    assert(roots != NULL);
    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    switch(roots->count_solutions) {

        case 0:
            printf("� ������� ��������� ��� ������ � �������������� ���������.\n");
            break;
        case 1:
            printf("������ ���������: %.*lf\n", DIGITS_AFTER_POINT, roots->x1);
            break;
        case 2:
            printf("����� ���������: %.*lf %.*lf\n", DIGITS_AFTER_POINT, roots->x1, DIGITS_AFTER_POINT, roots->x2);
            break;
        default:
            printf("����������� ��������� �������.");
            break;
    }
}
