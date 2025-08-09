/*
 * parse.h
 *
 * Function prototypes for parsing command line arguments, normalising
 * values and checking for duplicates and sorted order.  These
 * functions operate on stacks and integer arrays.  Input parsing
 * expects each argument to contain one or more integers separated by
 * spaces.  On invalid input the functions call error_exit() to
 * terminate the program gracefully.
 */

#ifndef PARSE_H
# define PARSE_H

# include "stack.h"

/* Parses command line arguments into a newly allocated integer array.
 * The `arr` pointer is set to the allocated array and the return
 * value is the number of integers parsed.  The function invokes
 * error_exit() on invalid input or allocation failure. */
int     parse_input(int argc, char **argv, int **arr);

/* Checks an integer array for duplicates.  Returns 1 if duplicates
 * exist or 0 otherwise. */
int     has_duplicates(int *arr, int size);

/* Normalises the values in an integer array to their sorted
 * rankings (0-based).  For example, [40, -2, 10] becomes [2, 0, 1]. */
void    normalize(int *arr, int size);

/* Tests whether a stack is sorted in ascending order.  Returns 1
 * when sorted or 0 otherwise. */
int     is_sorted(t_stack *a);

#endif