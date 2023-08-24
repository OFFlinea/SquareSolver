const int DIGITS_AFTER_POINT = 1;


struct SquareTrinomial
{
    double a;
    double b;
    double c;
};

struct Roots
{
    double x1 = 0;
    double x2 = 0;
    int count_solutions = -1;
};

void introduction(void);

void clear_buf(void);

void square_print(struct Roots *roots);

void square_input(struct SquareTrinomial *coeffs);
