//! Number of tests
const int N_TESTS = 7;
//! Infinite number of solutions, expressed by the number 3
const int INFINITE_SOLUTIONS = 3;
//! White text
const int WHITE = 0x0f;

//! Structure for storing the coefficients of a square equation
struct SquareTrinomial
{
    double a; //!< The coefficient before x squared
    double b; //!< Coefficient before x
    double c; //!< Free member
};

//! A structure storing the roots of a quadratic equation and the number of solutions
struct Roots
{
    double x1; //!< The first root of the equation
    double x2; //!< The second root of the equation
    int count_solutions; //!< Number of solutions to the equation
};
