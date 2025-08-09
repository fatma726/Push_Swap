/*
 * quicksort_b.c
 *
 * Implements the quick sort algorithm for sorting the top n elements
 * of stack B in descending order using stack A as auxiliary storage.
 * The algorithm selects a pivot value using the same median-of-three
 * heuristic as quicksort_a, partitions the top n elements of B
 * around the pivot, sorts the partitions recursively (sorting the
 * pushed elements in ascending order on A and the remaining elements
 * in descending order on B) and finally pushes the sorted partition
 * back to B.  Base cases handle partitions of size 1–3 directly
 * without recursion.  All functions adhere to the 42 coding style
 * constraints: no for loops, function length limits and separate
 * declarations.
 */

#include "../includes/push_swap.h"

/* Partition the top n elements of stack B around the pivot.  All
 * values greater than or equal to the pivot are pushed to A; all
 * smaller values are rotated within B.  The number of rotations
 * performed is stored in *rot and the number of pushed values
 * is returned. */
static int partition_b(t_stack *a, t_stack *b, int n, int pivot, int *rot)
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
        value = b->data[0];
        if (value >= pivot)
        {
            pa(a, b);
            pushed = pushed + 1;
        }
        else
        {
            rb(b);
            rotated = rotated + 1;
        }
        i = i + 1;
    }
    *rot = rotated;
    return (pushed);
}

/* Restore the original order of the rotated elements in stack B by
 * performing rot reverse rotations. */
static void restore_rotations_b(t_stack *b, int rot)
{
    while (rot > 0)
    {
        rrb(b);
        rot = rot - 1;
    }
}

/* Sort two or three elements in stack B in descending order. */
static void sort_small_b(t_stack *b, int n)
{
    int x;
    int y;
    int z;

    if (n <= 1)
        return;
    if (n == 2)
    {
        if (b->data[0] < b->data[1])
            sb(b);
        return;
    }
    /* n == 3 */
    x = b->data[0];
    y = b->data[1];
    z = b->data[2];
    if (x >= y && y >= z)
        return;
    if (x >= z && z >= y)
    {
        rb(b);
        sb(b);
        rrb(b);
        return;
    }
    if (y >= x && x >= z)
    {
        sb(b);
        return;
    }
    if (y >= z && z >= x)
    {
        rb(b);
        return;
    }
    if (z >= x && x >= y)
    {
        rrb(b);
        return;
    }
    /* Remaining case: z >= y && y >= x */
    rb(b);
    sb(b);
}

/* Quick sort the top n elements of stack B in descending order. */
void quick_sort_b(t_stack *a, t_stack *b, int n)
{
    int pivot;
    int pushed;
    int rot;

    if (n <= 3)
    {
        sort_small_b(b, n);
        return;
    }
    pivot = compute_pivot(b, n);
    pushed = partition_b(a, b, n, pivot, &rot);
    restore_rotations_b(b, rot);
    quick_sort_a(a, b, pushed);
    quick_sort_b(a, b, n - pushed);
    while (pushed > 0)
    {
        pb(a, b);
        pushed = pushed - 1;
    }
}