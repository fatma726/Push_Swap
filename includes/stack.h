/*
 * stack.h
 *
 * Definition of the stack structure and prototypes for stack operations
 * used in the push_swap project.  Operations are implemented in the
 * corresponding source files and respect the 42 coding standards: no
 * global variables, no for loops, and function bodies kept short.
 */

#ifndef STACK_H
# define STACK_H

/* Simple stack representation using a dynamic array.  The index 0
 * corresponds to the top of the stack.  The size field records the
 * number of elements currently stored.  When pushing or popping
 * elements, data is shifted accordingly. */
typedef struct s_stack
{
    int *data;
    int size;
}   t_stack;

/* Swap the first two elements on stack a */
void    sa(t_stack *a);
/* Swap the first two elements on stack b */
void    sb(t_stack *b);
/* Swap the first two elements of both stacks */
void    ss(t_stack *a, t_stack *b);
/* Push the top of b onto a */
void    pa(t_stack *a, t_stack *b);
/* Push the top of a onto b */
void    pb(t_stack *a, t_stack *b);
/* Rotate stack a upwards */
void    ra(t_stack *a);
/* Rotate stack b upwards */
void    rb(t_stack *b);
/* Rotate both stacks upwards */
void    rr(t_stack *a, t_stack *b);
/* Reverse rotate stack a downwards */
void    rra(t_stack *a);
/* Reverse rotate stack b downwards */
void    rrb(t_stack *b);
/* Reverse rotate both stacks downwards */
void    rrr(t_stack *a, t_stack *b);

#endif