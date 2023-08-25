//! The number of decimal places in the output numbers
const int DIGITS_AFTER_POINT = 1;

//! Program Description
void introduction(void);

//! Answer output
//! @param [in] roots An object of the Roots structure containing the roots of the equation and the number of roots
void square_print(const struct Roots *roots);

//! Entering the coefficients of the equation
//! @param [out] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
void square_input(struct SquareTrinomial *coeffs);

//! Clearing the input buffer
void clear_buf(void);
