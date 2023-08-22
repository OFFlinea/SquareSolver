#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(){
    double a = 0, b = 0, c = 0;
    printf("Введите коэффиценты квадратного уравнения: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a != 0) {
        const double d = b * b - 4 * a * c;
        if (d > 0) {
            const double d_sqrt = sqrt(d);
            double x1 = (-b + d_sqrt) / (2 * a);
            double x2 = (-b - d_sqrt) / (2 * a);
            printf("Корни уравнения: %.1lf %.1lf\n", x1, x2);
        }
        else if (d == 0) {
            double x = -b / (2 * a);
            printf("Корень уравнения: %.1lf\n", x);
        }
        else {
            printf("У данного уравнения нет корней в действительных величинах.\n");
        }
    }
    else {
        if (b != 0) {
            printf("Корень уравнения: %.1lf\n", -c / b);
        }
        else {
            printf((c != 0) ? "Бесконечное множество корней\n" : "У данного уравнения нет корней в действительных величинах.\n");
        }
    }
    return 0;
}
