/*
 * push_swap.h
 *
 * Main entrypoint for the sorting algorithm used in the push_swap
 * project.  The sort_stacks() function chooses an appropriate
 * strategy based on the number of elements and uses stack
 * operations to produce a sorted stack.  Other helper functions
 * reside in separate modules to respect the 42 coding standard.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

/* Sorts stack A using stack B as auxiliary storage.  The sequence
 * of operations is printed to the standard output.  On return,
 * stack A will contain the values in ascending order and stack B
 * will be empty. */
void    sort_stacks(t_stack *a, t_stack *b);

/* Helper functions for small sorts and quicksort */
void    sort_three(t_stack *a);
void    sort_4(t_stack *a, t_stack *b);
void    sort_5(t_stack *a, t_stack *b);
void    quick_sort_a(t_stack *a, t_stack *b, int n);
void    quick_sort_b(t_stack *a, t_stack *b, int n);
int     compute_pivot(t_stack *s, int n);

#endif