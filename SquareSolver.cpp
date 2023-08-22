#include <TXLib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPSILON = 1e-6;
const int DIGITS_AFTER_POINT = 1;
const int INFINITE_SOLUTIONS = 3;

/*struct SquareTrinomial
{
    double a = 0;
    double b = 0;
    double c = 0;
};

SquareTrinomial *aboba1;
(*aboba1).a
aboba1->a

SquareTrinomial aboba2;
aboba2.a*/



bool is_zero(double n);

bool is_greater(double n);

void square_solver(const double a, const double b, const double c);

void introduction(void);

void clear_buf(void);

void square_print(const int count_solutions, const double *x1, const double *x2);

void square_input(double *a, double *b, double *c);


int main(){

    introduction();

    double a = 0;
    double b = 0;
    double c = 0;

    square_input(&a, &b, &c);
    square_solver(a, b, c);

    return 0;
}


bool is_zero(double n) {

    assert(isfinite(n));

    return (fabs(n) < EPSILON) ? true : false;

}


void square_solver(const double a, const double b, const double c) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    int count_solutions = -1;
    double x1 = '0';
    double x2 = '0';

    if (!is_zero(a)) {

        const double d = b * b - 4 * a * c;

        if (is_greater(d)) {

            const double d_sqrt = sqrt(d);
            x1 = (-b + d_sqrt) / (2 * a);
            x2 = (-b - d_sqrt) / (2 * a);
            count_solutions = 2;
        }

        else if (is_zero(d)) {

            x1 = -b / (2 * a);
            count_solutions = 1;
        }

        else {

            count_solutions = 0;
        }
    }

    else {

        if (!is_zero(b)) {

            x1 = -c / b;
            count_solutions = 1;
        }

        else {

            count_solutions = (is_zero(c)) ? INFINITE_SOLUTIONS : 0;
        }
    }
    square_print(count_solutions, &x1, &x2);
}


void introduction(void){
    printf("Эта программа решает квадратное уравнение\n"
           "Введите коэффициенты квадратного уравнения: ");
}


void clear_buf(void) {
    int c = getchar();
    while((c = getchar()) != '\n');
}


bool is_greater(double n){

    assert(isfinite(n));

    return (n > EPSILON) ? true : false;
}


void square_print(const int count_solutions, const double *x1, const double *x2){
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(*x1));
    assert(isfinite(*x2));

    switch(count_solutions) {
        case 0:
            printf("У данного уравнения нет корней в действительных величинах.\n");
            break;
        case 1:
            printf("Корень уравнения: %.*lf\n", DIGITS_AFTER_POINT, *x1);
            break;
        case 2:
            printf("Корни уравнения: %.*lf %.*lf\n", DIGITS_AFTER_POINT, *x1, DIGITS_AFTER_POINT, *x2);
            break;
        default:
            printf("Бесконечное множество решений.");
            break;
    }
}


void square_input(double *a, double *b, double *c){
    while(scanf("%lf %lf %lf", &(*a), &(*b), &(*c)) != 3) {  // сделать функцию
        clear_buf();

        printf("Вы ввели некорректные данные."
        " Вы должны ввести 3 числа через пробелы, попробуйте снова: ");

    }
}
