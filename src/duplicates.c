/*
 * duplicates.c
 *
 * Provides a function to check for duplicate values in an integer
 * array.  Duplicate values are not allowed in the push_swap project,
 * so encountering one results in an error.  The check uses nested
 * while loops and does not rely on any forbidden constructs.
 */

#include "../includes/parse.h"
#include "../libft/libft.h"

int has_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j = j + 1;
        }
        i = i + 1;
    }
    return (0);
}