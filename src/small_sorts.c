/*
 * small_sorts.c
 *
 * Implements helper routines for sorting very small stacks (size 2
 * through 5) in the push_swap project.  These routines use
 * only the permitted stack operations and are optimised to
 * produce at most 12 operations for five elements, as required
 * by the project evaluation.  All loops are written as while
 * loops and comply with the 42 coding standard.
 */

#include "../includes/push_swap.h"
#include "../includes/parse.h"

/* Push the smallest element of stack a to stack b */
static void push_min_to_b(t_stack *a, t_stack *b)
{
    int i;
    int min;
    int pos;

    i = 0;
    min = a->data[0];
    pos = 0;
    while (i < a->size)
    {
        if (a->data[i] < min)
        {
            min = a->data[i];
            pos = i;
        }
        i = i + 1;
    }
    if (pos <= a->size / 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos = pos - 1;
        }
    }
    else
    {
        i = a->size - pos;
        while (i > 0)
        {
            rra(a);
            i = i - 1;
        }
    }
    pb(a, b);
}

/* Sort three numbers on stack a in ascending order */
void sort_three(t_stack *a)
{
    int x;
    int y;
    int z;

    x = a->data[0];
    y = a->data[1];
    z = a->data[2];
    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && x > z && y > z)
        rra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
}

/* Sort four numbers on stack a using stack b */
void sort_4(t_stack *a, t_stack *b)
{
    push_min_to_b(a, b);
    /* Now three elements remain in a */
    sort_three(a);
    pa(a, b);
}

/* Sort five numbers on stack a using stack b */
void sort_5(t_stack *a, t_stack *b)
{
    /* Push the two smallest values to b */
    push_min_to_b(a, b);
    push_min_to_b(a, b);
    /* Sort the remaining three values */
    sort_three(a);
    /* Push back the two smallest; they will be in correct order */
    pa(a, b);
    pa(a, b);
}