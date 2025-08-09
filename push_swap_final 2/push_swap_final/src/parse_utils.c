/*
 * parse_utils.c
 *
 * Helper functions used during parsing.  Currently provides an
 * error_exit() function that prints an error message and
 * terminates the program.  Additional helpers may be added here.
 */

#include "../includes/parse_utils.h"
#include "../libft/libft.h"
#include <stdlib.h>

void error_exit(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}