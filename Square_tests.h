//! Asks the user if the program needs to be tested
void test_question(void);

//! Сounts the number of lines in the file
//! @param filename[] Name of the transferred file
int count_lines(const char filename[]);

//! Testing the program
//! @param [in] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
//! @param [out] roots An object of the Roots structure containing the roots of the equation and the number of roots
//! @param [in] refroots An object of the Roots structure containing the correct roots of the equation and the correct number of roots
int TestOne(const struct SquareTrinomial *coeffs, struct Roots *roots, const struct Roots *refroots);

//! Does some tests
int TestAll(void);

//! Reads the data for the program test and tests it
//! @param filename[] Name of the test file
void test_file(const char filename[]);
