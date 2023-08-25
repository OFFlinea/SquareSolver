//! Asks the user if the program needs to be tested
void test_question(void);

//! Testing the program
//! @param [in] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
//! @param [out] roots An object of the Roots structure containing the roots of the equation and the number of roots
//! @param [in] refroots An object of the Roots structure containing the correct roots of the equation and the correct number of roots
int TestOne(const struct SquareTrinomial *coeffs, struct Roots *roots, const struct Roots *refroots);

//! Does some tests
int TestAll(void);
