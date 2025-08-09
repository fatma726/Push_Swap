/*
 * quicksort_a.c
 *
 * Implements the quick sort algorithm for sorting stack A in
 * ascending order using stack B as auxiliary storage.  The
 * algorithm selects a pivot value using a median-of-three
 * heuristic, partitions the top n elements of A into those
 * less than or equal to the pivot (pushed to B) and those
 * greater than the pivot (rotated within A), then recursively
 * sorts the partitions.  After sorting, the partition pushed
 * to B is sorted by quick_sort_b and then pushed back to A.
 * Helper functions are defined to compute the pivot, partition
 * stack A and restore rotations.  All loops use while
 * constructs and functions remain under 25 lines.
 */

#include "../includes/push_swap.h"
#include "../includes/parse_utils.h"

/* Compute a pivot using the median-of-three method.  The pivot is
 * chosen as the median of the first, middle and last elements
 * among the top n elements of stack s. */
int compute_pivot(t_stack *s, int n)
{
    int a;
    int b;
    int c;
    int pivot;

    a = s->data[0];
    b = s->data[n / 2];
    c = s->data[n - 1];
    if ((a >= b && a <= c) || (a <= b && a >= c))
        pivot = a;
    else if ((b >= a && b <= c) || (b <= a && b >= c))
        pivot = b;
    else
        pivot = c;
    return (pivot);
}

/* Partition the top n elements of stack A around the pivot.  All
 * values less than or equal to the pivot are pushed to B; all
 * greater values are rotated within A.  The number of rotations
 * performed is stored in *rot and the number of pushed values
 * is returned. */
static int partition_a(t_stack *a, t_stack *b, int n, int pivot, int *rot)
{
    int i;
    int pushed;
    int rotated;
    int value;

    i = 0;
    pushed = 0;
    rotated = 0;
    while (i < n)
    {
        value = a->data[0];
        if (value <= pivot)
        {
            pb(a, b);
            pushed = pushed + 1;
        }
        else
        {
            ra(a);
            rotated = rotated + 1;
        }
        i = i + 1;
    }
    *rot = rotated;
    return (pushed);
}

/* Restore the original order of the rotated elements in stack A by
 * performing rot reverse rotations. */
static void restore_rotations_a(t_stack *a, int rot)
{
    while (rot > 0)
    {
        rra(a);
        rot = rot - 1;
    }
}

/* Quick sort the top n elements of stack A in ascending order. */
void quick_sort_a(t_stack *a, t_stack *b, int n)
{
    int pivot;
    int pushed;
    int rot;

    if (n <= 3)
    {
        if (n == 2 && a->data[0] > a->data[1])
            sa(a);
        else if (n == 3)
            sort_three(a);
        return;
    }
    pivot = compute_pivot(a, n);
    pushed = partition_a(a, b, n, pivot, &rot);
    restore_rotations_a(a, rot);
    quick_sort_a(a, b, n - pushed);
    quick_sort_b(a, b, pushed);
    while (pushed > 0)
    {
        pa(a, b);
        pushed = pushed - 1;
    }
}