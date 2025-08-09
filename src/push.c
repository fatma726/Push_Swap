/*
 * push.c
 *
 * Implements push operations for the push_swap project.  Pushing
 * moves the top element from one stack to the other.  The pa
 * instruction pushes the top of stack b to stack a, while pb
 * pushes the top of a to b.  The helper function push_stack
 * performs the transfer without printing.
 */

#include "../includes/stack.h"
#include "../libft/libft.h"

/* Move the top element from src to dst */
static void push_stack(t_stack *src, t_stack *dst)
{
    int i;
    if (!src || !dst || src->size == 0)
        return;
    i = dst->size;
    while (i > 0)
    {
        dst->data[i] = dst->data[i - 1];
        i = i - 1;
    }
    dst->data[0] = src->data[0];
    dst->size = dst->size + 1;
    i = 0;
    while (i < src->size - 1)
    {
        src->data[i] = src->data[i + 1];
        i = i + 1;
    }
    src->size = src->size - 1;
}

void pa(t_stack *a, t_stack *b)
{
    if (b && a)
    {
        if (b->size > 0)
        {
            push_stack(b, a);
            ft_putstr_fd("pa", 1);
            ft_putchar_fd('\n', 1);
        }
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a && b)
    {
        if (a->size > 0)
        {
            push_stack(a, b);
            ft_putstr_fd("pb", 1);
            ft_putchar_fd('\n', 1);
        }
    }
}