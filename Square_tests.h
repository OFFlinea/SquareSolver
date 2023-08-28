#ifndef SQUARE_TESTS_H
#define SQUARE_TESTS_H

//! Number of tests
//const int N_TESTS = 7;

//! Structure for tests
struct Test
{
    double a; //!< The coefficient before x squared
    double b; //!< Coefficient before x
    double c; //!< Free member
    double x1; //!< The first root of the equation
    double x2; //!< The second root of the equation
    int count_solutions; //!< Number of solutions to the equation
};

//! Asks the user if the program needs to be tested
void test_question(void);

//! Сounts the number of lines in the file
//! @param filename[] Name of the transferred file
int count_lines(const char filename[]);

//! Testing the program
//! @param [in] tests_params Variable transmitting test parameters
//! @param [in] refroots An object of the Roots structure containing the correct roots of the equation and the correct number of roots
int TestOne(const struct Test *tests_params, struct Roots *roots);

//! Does some tests
void TestAll(void);

//! Reads the data for the program test and tests it
//! @param filename[] Name of the test file
void test_file(const char filename[]);
#endif
