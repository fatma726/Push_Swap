/*
 * normalize.c
 *
 * Normalises an array of integers by mapping each value to its
 * position in the sorted order.  This transformation replaces the
 * original values with a range from 0 to n‑1 and simplifies
 * sorting operations such as radix sort.  The file also contains
 * helper functions to copy arrays, sort them and find the rank of
 * a value.  All loops are implemented with while loops to comply
 * with the project rules.
 */

#include "../includes/parse.h"
#include "../includes/parse_utils.h"
#include "../libft/libft.h"
#include <stdlib.h>

/* Copy the contents of src into dst */
static void copy_array(int *src, int *dst, int size)
{
    int i;
    i = 0;
    while (i < size)
    {
        dst[i] = src[i];
        i = i + 1;
    }
}

/* Sort an integer array in ascending order using a simple bubble sort */
static void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

/* Find the index of value in arr */
static int find_index(int *arr, int size, int value)
{
    int i;
    i = 0;
    while (i < size)
    {
        if (arr[i] == value)
            return (i);
        i = i + 1;
    }
    return (0);
}

/* Replace each element with its rank in the sorted order */
void normalize(int *arr, int size)
{
    int *copy;
    int i;
    int rank;

    copy = (int *)malloc(sizeof(int) * size);
    if (!copy)
        error_exit();
    copy_array(arr, copy, size);
    sort_array(copy, size);
    i = 0;
    while (i < size)
    {
        rank = find_index(copy, size, arr[i]);
        arr[i] = rank;
        i = i + 1;
    }
    free(copy);
}