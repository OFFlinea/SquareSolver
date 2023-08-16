#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void){
double a, b, c, d;
printf("Введите коэффиценты квадратного уравнения: ");
scanf("%lf %lf %lf", &a, &b, &c);
d = pow(b, 2) - 4 * a * c;
if (a > 0 || a < 0){
    if (d > 0){
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("Корни уравнения: %.1lf %.1lf", x1, x2);
    }
    else if (!(d > 0 || d < 0)){
        double x = (-b) / (2 * a);
        printf("Корень уравнения: %.1lf", x);
    }
    else
    printf("У данного уравнения нет корней в действительных величинах.");
}
else
printf("Это уравнение не квадратное!);
return 0;
}
