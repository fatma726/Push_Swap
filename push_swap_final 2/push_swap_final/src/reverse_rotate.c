/*
 * reverse_rotate.c
 *
 * Implements reverse rotation operations for the push_swap project.
 * A reverse rotation shifts all elements of a stack down by one
 * position, moving the last element to the top.  The rrr
 * instruction applies the reverse rotation to both stacks.
 */

#include "../includes/stack.h"
#include "../libft/libft.h"

/* Reverse rotate a stack without printing */
static void reverse_rotate_stack(t_stack *s)
{
    int last;
    int i;
    if (s && s->size > 1)
    {
        last = s->data[s->size - 1];
        i = s->size - 1;
        while (i > 0)
        {
            s->data[i] = s->data[i - 1];
            i = i - 1;
        }
        s->data[0] = last;
    }
}

void rra(t_stack *a)
{
    if (a && a->size > 1)
    {
        reverse_rotate_stack(a);
        ft_putstr_fd("rra", 1);
        ft_putchar_fd('\n', 1);
    }
}

void rrb(t_stack *b)
{
    if (b && b->size > 1)
    {
        reverse_rotate_stack(b);
        ft_putstr_fd("rrb", 1);
        ft_putchar_fd('\n', 1);
    }
}

void rrr(t_stack *a, t_stack *b)
{
    int executed;

    executed = 0;
    if (a && a->size > 1)
    {
        reverse_rotate_stack(a);
        executed = 1;
    }
    if (b && b->size > 1)
    {
        reverse_rotate_stack(b);
        executed = 1;
    }
    if (executed)
    {
        ft_putstr_fd("rrr", 1);
        ft_putchar_fd('\n', 1);
    }
}