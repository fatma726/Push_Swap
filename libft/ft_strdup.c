/*
 * ft_strdup.c
 *
 * Allocates sufficient memory for a copy of the string s1, does
 * the copy, and returns a pointer to it.  The copy is null‑
 * terminated.  Returns NULL if the allocation fails.  Uses only
 * functions implemented in libft.
 */

#include "libft.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    size_t len;
    char   *copy;
    size_t i;

    len = ft_strlen(s1);
    copy = (char *)malloc(len + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < len)
    {
        copy[i] = s1[i];
        i = i + 1;
    }
    copy[len] = '\0';
    return (copy);
}