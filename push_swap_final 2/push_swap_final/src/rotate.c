/*
 * rotate.c
 *
 * Implements rotation operations for the push_swap project.  A
 * rotation shifts all elements of a stack up by one position,
 * moving the first element to the last.  The rr instruction
 * performs the rotation on both stacks simultaneously.  All
 * operations print their identifiers when they perform an action.
 */

#include "../includes/stack.h"
#include "../libft/libft.h"

/* Rotate a stack upwards without printing */
static void rotate_stack(t_stack *s)
{
    int first;
    int i;
    if (s && s->size > 1)
    {
        first = s->data[0];
        i = 0;
        while (i < s->size - 1)
        {
            s->data[i] = s->data[i + 1];
            i = i + 1;
        }
        s->data[s->size - 1] = first;
    }
}

void ra(t_stack *a)
{
    if (a && a->size > 1)
    {
        rotate_stack(a);
        ft_putstr_fd("ra", 1);
        ft_putchar_fd('\n', 1);
    }
}

void rb(t_stack *b)
{
    if (b && b->size > 1)
    {
        rotate_stack(b);
        ft_putstr_fd("rb", 1);
        ft_putchar_fd('\n', 1);
    }
}

void rr(t_stack *a, t_stack *b)
{
    int executed;

    executed = 0;
    if (a && a->size > 1)
    {
        rotate_stack(a);
        executed = 1;
    }
    if (b && b->size > 1)
    {
        rotate_stack(b);
        executed = 1;
    }
    if (executed)
    {
        ft_putstr_fd("rr", 1);
        ft_putchar_fd('\n', 1);
    }
}