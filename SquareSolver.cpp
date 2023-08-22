#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double epsilon = 1e-6;


bool is_zero(double n);

void square_solver(const double *a, const double *b, const double *c);


int main(){

    double a = 0, b = 0, c = 0;

    printf("��� ��������� ������ ���������� ���������\n"
           "������� ����������� ����������� ���������: ");

    if(scanf("%lf %lf %lf", &a, &b, &c) != 3) {

        printf("�� ����� ������������ ������. �� ������ ������ 3 ����� ����� �������, ���������� �����.");
    }
    else {

        square_solver(&a, &b, &c);
    }
    return 0;
}


bool is_zero(double n) {

    return (fabs(n) < epsilon) ? true : false;

}


void square_solver(const double *a, const double *b, const double *c) {

    if (!is_zero(*a)) {

        const double d = *b * *b - 4 * *a * *c;

        if (d > 0) {

            const double d_sqrt = sqrt(d);
            double x1 = (-*b + d_sqrt) / (2 * *a);
            double x2 = (-*b - d_sqrt) / (2 * *a);
            printf("����� ���������: %.1lf %.1lf\n", x1, x2);
        }

        else if (is_zero(d)) {

            double x = -*b / (2 * *a);
            printf("������ ���������: %.1lf\n", x);
        }

        else {
            printf("� ������� ��������� ��� ������ � �������������� ���������.\n");
        }
    }

    else {

        if (!is_zero(*b)) {

            printf("������ ���������: %.1lf\n", -*c / *b);
        }

        else {
            printf((is_zero(*c)) ? "����������� ��������� ������\n" : "� ������� ��������� ��� ������ � �������������� ���������.\n");
        }
    }
}
