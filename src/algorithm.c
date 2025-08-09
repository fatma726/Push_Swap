/*
 * algorithm.c
 *
 * Implements the high level sorting logic for the push_swap project.
 * Depending on the size of the input stack, it chooses between
 * simple sorting routines for two or three elements and a radix
 * based approach for larger inputs.  The functions here rely on
 * stack operations defined elsewhere and adhere to the 42 coding
 * style guidelines.
 */

#include "../includes/push_swap.h"
#include "../includes/parse.h"

/* Forward declaration of quick sort functions implemented in quicksort_a.c and quicksort_b.c */
void quick_sort_a(t_stack *a, t_stack *b, int n);
void sort_three(t_stack *a);
void sort_4(t_stack *a, t_stack *b);
void sort_5(t_stack *a, t_stack *b);

/* Sort two numbers */
static void sort_two(t_stack *a)
{
    if (a->data[0] > a->data[1])
        sa(a);
}

/* sort_three is implemented in small_sorts.c */

/* Main sorting dispatcher */
void sort_stacks(t_stack *a, t_stack *b)
{
    if (!a)
        return;
    if (a->size < 2 || is_sorted(a))
        return;
    if (a->size == 2)
    {
        sort_two(a);
        return;
    }
    if (a->size == 3)
    {
        sort_three(a);
        return;
    }
    if (a->size == 4)
    {
        sort_4(a, b);
        return;
    }
    if (a->size == 5)
    {
        sort_5(a, b);
        return;
    }
    /* Use quick sort for larger inputs */
    quick_sort_a(a, b, a->size);
}