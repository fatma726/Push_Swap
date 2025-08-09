/*
 * radix.c
 *
 * Contains an implementation of the radix sort algorithm used to
 * efficiently sort larger sequences of numbers in the push_swap
 * project.  Values must be normalised (0..n‑1) before calling
 * this function.  Helper functions compute the maximum value and
 * determine how many bits are required to represent it.  All
 * loops use while constructs and abide by the 42 coding rules.
 */

#include "push_swap.h"

/* Find the maximum value in stack a */
static int find_max_value(t_stack *a)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while (i < a->size)
    {
        if (a->data[i] > max)
            max = a->data[i];
        i = i + 1;
    }
    return (max);
}

/* Compute the number of bits required to represent max */
static int get_max_bits(int max)
{
    int bits;

    bits = 0;
    while ((max >> bits) != 0)
        bits = bits + 1;
    return (bits);
}

/* Perform radix sort on stack a using stack b */
void radix_sort(t_stack *a, t_stack *b)
{
    int max_value;
    int max_bits;
    int bit;
    int i;
    int count;

    max_value = find_max_value(a);
    max_bits = get_max_bits(max_value);
    bit = 0;
    while (bit < max_bits)
    {
        count = a->size;
        i = 0;
        while (i < count)
        {
            if (((a->data[0] >> bit) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            i = i + 1;
        }
        while (b->size > 0)
            pa(a, b);
        bit = bit + 1;
    }
}