/*
 * libft.h
 *
 * Header file for the minimal C library used by the push_swap project.
 * Only the functions required by the project are declared here.  Each
 * function adheres to the 42 coding standards: no for loops, no
 * assignments on the same line as declarations, and concise
 * implementation.  See the individual source files in this
 * directory for details.
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* Character classification */
int     ft_isdigit(int c);
int     ft_isspace(int c);

/* String functions */
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);

/* Output functions */
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);

#endif