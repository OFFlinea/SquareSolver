#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void){
double a, b, c, d;
printf("������� ����������� ����������� ���������: ");
scanf("%lf %lf %lf", &a, &b, &c);
d = pow(b, 2) - 4 * a * c;
if (a > 0 || a < 0){
    if (d > 0){
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("����� ���������: %.1lf %.1lf", x1, x2);
    }
    else if (!(d > 0 || d < 0)){
        double x = (-b) / (2 * a);
        printf("������ ���������: %.1lf", x);
    }
    else
    printf("� ������� ��������� ��� ������ � �������������� ���������.");
}
else
printf("��� ��������� �� ����������!);
return 0;
}
