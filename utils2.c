/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:46:49 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/09 20:47:31 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *error_msg)
{
	write(2, "Error\n", 6);
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a && a->array)
		free(a->array);
	if (b && b->array)
		free(b->array);
}

int	is_digits(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *s)
{
	long	num;

	if (!is_digits(s))
		return (0);
	num = ft_atoi(s);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
