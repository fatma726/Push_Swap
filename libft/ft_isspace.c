/*
 * ft_isspace.c
 *
 * Determines whether a character is a whitespace character.  Returns
 * 1 for spaces, tabs, newlines, carriage returns, vertical tabs,
 * and form feeds; otherwise returns 0.  This function is used to
 * parse input strings without relying on the C standard library.
 */

#include "libft.h"

int ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
        return (1);
    return (0);
}