/*
 * swap.c
 *
 * Implements swap operations for the push_swap project.  Swapping
 * exchanges the first two elements of a stack when there are at
 * least two elements.  The ss operation swaps both stacks
 * simultaneously.  Outputs the corresponding instruction
 * identifiers to standard output using libft functions.
 */

#include "../includes/stack.h"
#include "../libft/libft.h"

/* Swap the first two elements of a stack without printing */
static void swap_stack(t_stack *s)
{
    int tmp;

    if (s && s->size > 1)
    {
        tmp = s->data[0];
        s->data[0] = s->data[1];
        s->data[1] = tmp;
    }
}

void sa(t_stack *a)
{
    if (a && a->size > 1)
    {
        swap_stack(a);
        ft_putstr_fd("sa", 1);
        ft_putchar_fd('\n', 1);
    }
}

void sb(t_stack *b)
{
    if (b && b->size > 1)
    {
        swap_stack(b);
        ft_putstr_fd("sb", 1);
        ft_putchar_fd('\n', 1);
    }
}

void ss(t_stack *a, t_stack *b)
{
    int executed;

    executed = 0;
    if (a && a->size > 1)
    {
        swap_stack(a);
        executed = 1;
    }
    if (b && b->size > 1)
    {
        swap_stack(b);
        executed = 1;
    }
    if (executed)
    {
        ft_putstr_fd("ss", 1);
        ft_putchar_fd('\n', 1);
    }
}