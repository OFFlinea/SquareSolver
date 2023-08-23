#include <TXLib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

const double EPSILON = 1e-6;
const int DIGITS_AFTER_POINT = 1;
const int INFINITE_SOLUTIONS = 3;


struct SquareTrinomial
{
    double a = 0;
    double b = 0;
    double c = 0;
};

struct Roots
{
    double x1 = 0;
    double x2 = 0;
    int count_solutions = -1;
};


bool is_zero(double n);

bool is_greater(double n);

void square_solver(struct SquareTrinomial *coeffs);

void introduction(void);

void clear_buf(void);

void square_print(struct Roots *roots);

void square_input(struct SquareTrinomial *coeffs);


int main(){

    introduction();

    SquareTrinomial coeffs;

    square_input(&coeffs);
    square_solver(&coeffs);

    return 0;
}


bool is_zero(double n) {

    assert(isfinite(n));

    return (fabs(n) < EPSILON) ? true : false;

}


void square_solver(SquareTrinomial *coeffs) {

    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    struct Roots roots;

    if (!is_zero(coeffs->a)) {

        const double d = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;

        if (is_greater(d)) {

            const double d_sqrt = sqrt(d);
            roots.x1 = (-coeffs->b + d_sqrt) / (2 * coeffs->a);
            roots.x2 = (-coeffs->b - d_sqrt) / (2 * coeffs->a);
            roots.count_solutions = 2;
        }

        else if (is_zero(d)) {

            roots.x1 = -coeffs->b / (2 * coeffs->a);
            roots.count_solutions = 1;
        }

        else {

            roots.count_solutions = 0;
        }
    }

    else {

        if (!is_zero(coeffs->b)) {

            roots.x1 = -coeffs->c / coeffs->b;
            roots.count_solutions = 1;
        }

        else {

            roots.count_solutions = (is_zero(coeffs->c)) ? INFINITE_SOLUTIONS : 0;
        }
    }
    square_print(&roots);
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


void square_print(struct Roots *roots){

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
            printf("Корни уравнения: %.*lf %.*lf\n", DIGITS_AFTER_POINT, roots->x1, DIGITS_AFTER_POINT, roots->x2);
            break;
        default:
            printf("Бесконечное множество решений.");
            break;
    }
}


void square_input(struct SquareTrinomial *coeffs){
    while(scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c) != 3) {

        clear_buf();

        printf("Вы ввели некорректные данные."
        " Вы должны ввести 3 числа через пробелы, попробуйте снова: ");

    }
}
