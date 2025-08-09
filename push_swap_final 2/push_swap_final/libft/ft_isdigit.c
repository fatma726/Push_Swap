/*
 * ft_isdigit.c
 *
 * Checks whether the given character code corresponds to a decimal
 * digit.  Returns 1 if the character is a digit ('0' through '9')
 * and 0 otherwise.  Implemented without using the standard library.
 */

#include "libft.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}