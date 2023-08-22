#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const double epsilon = 1e-6;


bool is_zero(double n);

void square_solver(const double *a, const double *b, const double *c);


int main(){

    double a = 0, b = 0, c = 0;

    printf("Эта программа решает квадратное уравнение\n"
           "Введите коэффиценты квадратного уравнения: ");

    if(scanf("%lf %lf %lf", &a, &b, &c) != 3) {

        printf("Вы ввели некорректные данные. Вы должны ввести 3 числа через пробелы, попробуйте снова.");
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
            printf("Корни уравнения: %.1lf %.1lf\n", x1, x2);
        }

        else if (is_zero(d)) {

            double x = -*b / (2 * *a);
            printf("Корень уравнения: %.1lf\n", x);
        }

        else {
            printf("У данного уравнения нет корней в действительных величинах.\n");
        }
    }

    else {

        if (!is_zero(*b)) {

            printf("Корень уравнения: %.1lf\n", -*c / *b);
        }

        else {
            printf((is_zero(*c)) ? "Бесконечное множество корней\n" : "У данного уравнения нет корней в действительных величинах.\n");
        }
    }
}
