#ifndef SQUARE_IO_H
#define SQUARE_IO_H

//! The number of decimal places in the output numbers
const int DIGITS_AFTER_POINT = 1;

//! Brief program description
void introduction(void);

//! Description of the program
void help(void);

//! Answer output
//! @param [in] roots An object of the Roots structure containing the roots of the equation and the number of roots
void square_print(const struct Roots *roots);

//! Entering the coefficients of the equation
//! @param [out] coeffs An object of the SquareTrinomial structure containing the coefficients of the square equation
void square_input(struct SquareTrinomial *coeffs);

//! Clearing the input buffer
void clear_buf(void);

//! If find EOF, will terminate the program
//! @param [in] c Symbol from the input buffer
void eof_control(const int c);

//! Сhecks the command line for keywords
//! @param [in] argc Number of lines entered from the command line
//! @param [in] argv List of entered lines from the command line
void command_check(int argc, char *argv[]);
#endif
