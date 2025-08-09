/*
 * ft_strlen.c
 *
 * Computes the length of a null‑terminated string.  The return
 * value is the number of characters preceding the terminating null
 * byte.  This implementation avoids using any standard library
 * functions and complies with the 42 coding style.
 */

#include "libft.h"

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}