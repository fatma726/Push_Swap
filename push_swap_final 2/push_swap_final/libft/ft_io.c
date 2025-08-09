/*
 * ft_io.c
 *
 * Basic output functions for the push_swap project.  These
 * functions write characters and strings to a given file
 * descriptor using the write system call.  They avoid using the
 * standard I/O library and adhere to the 42 coding standards.
 */

#include "libft.h"
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
    int i;

    if (!s)
        return;
    i = 0;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}