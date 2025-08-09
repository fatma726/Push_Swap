/*
 * parse.c
 *
 * Implements the parsing of command line arguments into an array
 * of integers.  Each argument may contain one or more integers
 * separated by whitespace.  The file also counts the number of
 * numeric tokens and converts substrings to integers while
 * checking for overflow and invalid characters.  All loops use
 * while constructs and variable assignments are separated from
 * declarations in accordance with the 42 coding standards.
 */

#include "../includes/parse.h"
#include "../includes/parse_utils.h"
#include "../libft/libft.h"
#include <stdlib.h>

/* Forward declarations of static helper functions */
static int  count_tokens_in_string(char *s);
static void parse_numbers_in_string(char *s, int *arr, int *index, int *numbers);
static int  parse_number(char *s, int *pos, int *numbers);

/* Parse all arguments into a newly allocated array of integers */
int parse_input(int argc, char **argv, int **arr)
{
    int i;
    int total;
    int *numbers;
    int idx;

    i = 1;
    total = 0;
    while (i < argc)
    {
        total = total + count_tokens_in_string(argv[i]);
        i = i + 1;
    }
    numbers = (int *)malloc(sizeof(int) * total);
    if (!numbers)
        error_exit();
    idx = 0;
    i = 1;
    while (i < argc)
    {
        /* Pass numbers pointer so parse_number can free on error */
        parse_numbers_in_string(argv[i], numbers, &idx, numbers);
        i = i + 1;
    }
    if (has_duplicates(numbers, total))
    {
        free(numbers);
        error_exit();
    }
    *arr = numbers;
    return (total);
}

/* Count numeric tokens in a single argument string */
static int count_tokens_in_string(char *s)
{
    int pos;
    int count;

    pos = 0;
    count = 0;
    while (s[pos])
    {
        while (s[pos] && ft_isspace(s[pos]))
            pos = pos + 1;
        if (!s[pos])
            break;
        if (s[pos] == '+' || s[pos] == '-')
        {
            pos = pos + 1;
        }
        if (!ft_isdigit(s[pos]))
            error_exit();
        while (s[pos] && ft_isdigit(s[pos]))
            pos = pos + 1;
        count = count + 1;
        while (s[pos] && ft_isspace(s[pos]))
            pos = pos + 1;
    }
    return (count);
}

/* Parse numbers from a string into arr; update index */
static void parse_numbers_in_string(char *s, int *arr, int *index, int *numbers)
{
    int pos;
    int value;

    pos = 0;
    while (s[pos])
    {
        while (s[pos] && ft_isspace(s[pos]))
            pos = pos + 1;
        if (!s[pos])
            break;
        value = parse_number(s, &pos, numbers);
        arr[*index] = value;
        *index = *index + 1;
        while (s[pos] && ft_isspace(s[pos]))
            pos = pos + 1;
    }
}

/* Convert a substring starting at pos into an integer */
static int parse_number(char *s, int *pos, int *numbers)
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    if (s[*pos] == '-' || s[*pos] == '+')
    {
        if (s[*pos] == '-')
            sign = -1;
        *pos = *pos + 1;
    }
    if (!ft_isdigit(s[*pos]))
    {
        if (numbers)
            free(numbers);
        error_exit();
    }
    while (s[*pos] && ft_isdigit(s[*pos]))
    {
        result = result * 10 + (s[*pos] - '0');
        *pos = *pos + 1;
        if ((sign == 1 && result > 2147483647L) || (sign == -1 && result > 2147483648L))
        {
            if (numbers)
                free(numbers);
            error_exit();
        }
    }
    return ((int)(result * sign));
}