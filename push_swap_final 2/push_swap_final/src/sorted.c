/*
 * sorted.c
 *
 * Checks whether a stack is sorted in ascending order.  The
 * implementation uses a simple while loop to iterate over
 * neighbouring pairs of elements.  Returns 1 if the stack is
 * sorted or has fewer than two elements, and 0 otherwise.
 */

#include "../includes/parse.h"

int is_sorted(t_stack *a)
{
    int i;

    if (!a || a->size < 2)
        return (1);
    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i = i + 1;
    }
    return (1);
}