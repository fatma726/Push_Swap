/*
 * parse_utils.h
 *
 * Prototypes for utility functions used during parsing.  Currently
 * includes only error_exit(), which prints an error message and
 * terminates the program.  Additional parsing helpers may be added
 * here in the future.  These helpers abide by the 42 coding
 * standards.
 */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

/* Print "Error" to the standard error stream and exit the program. */
void    error_exit(void);

#endif