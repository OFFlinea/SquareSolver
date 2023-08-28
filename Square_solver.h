//! Accuracy of comparison
const double EPSILON = 1e-6;

//! Comparing a float number with zero
//! @param [in] n A float number that is compared to zero
bool is_zero(double n);

//! Check: is the float number greater than zero
//! @param [in] n A float number that is compared to zero
bool is_greater_than_zero(double n);

//! Comparison of float numbers
//! @param [in] x A float number
//! @param [in] y A float number
bool f_comparison(double x, double y);

//! Calculation of the roots of the equation
//! @param [in] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
//! @param [out] roots An object of the Roots structure containing the roots of the equation and the number of roots
void square_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);

//! Calculation of the root of a nonlinear equation
//! @param [in] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
//! @param [out] roots An object of the Roots structure containing the roots of the equation and the number of rootsй
void linear_solver(const struct SquareTrinomial *coeffs, struct Roots *roots);
