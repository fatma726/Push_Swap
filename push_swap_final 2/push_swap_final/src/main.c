/*
 * main.c
 *
 * Entry point for the push_swap program.  Parses the command
 * line arguments into an array of integers, normalises the
 * values, initialises two stacks and invokes the sorting
 * algorithm.  Frees all allocated memory before exiting.  Does
 * not perform any stack operations when the input is already
 * sorted or contains fewer than two numbers.
 */

#include "../includes/parse.h"
#include "../includes/parse_utils.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    int     *values;
    int     count;
    t_stack a;
    t_stack b;

    values = NULL;
    count = parse_input(argc, argv, &values);
    if (count <= 0)
    {
        free(values);
        return (0);
    }
    normalize(values, count);
    a.data = values;
    a.size = count;
    b.data = (int *)malloc(sizeof(int) * count);
    if (!b.data)
        error_exit();
    b.size = 0;
    sort_stacks(&a, &b);
    free(a.data);
    free(b.data);
    return (0);
}