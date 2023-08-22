#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(){
    double a = 0, b = 0, c = 0;
    printf("������� ����������� ����������� ���������: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a != 0) {
        const double d = b * b - 4 * a * c;
        if (d > 0) {
            const double d_sqrt = sqrt(d);
            double x1 = (-b + d_sqrt) / (2 * a);
            double x2 = (-b - d_sqrt) / (2 * a);
            printf("����� ���������: %.1lf %.1lf\n", x1, x2);
        }
        else if (d == 0) {
            double x = -b / (2 * a);
            printf("������ ���������: %.1lf\n", x);
        }
        else {
            printf("� ������� ��������� ��� ������ � �������������� ���������.\n");
        }
    }
    else {
        if (b != 0) {
            printf("������ ���������: %.1lf\n", -c / b);
        }
        else {
            printf((c != 0) ? "����������� ��������� ������\n" : "� ������� ��������� ��� ������ � �������������� ���������.\n");
        }
    }
    return 0;
}
