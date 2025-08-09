/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 18:59:35 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/09 18:59:37 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot(t_stack *stack, int *sorted, int nb)
{
	int	pivot;

	if (nb > stack->size)
		pivot = sorted[stack->size - 1];
	else
		pivot = sorted[nb - 1];
	return (pivot);
}

static void	push_to_b(t_stack *a, t_stack *b, int pivot, int pivot_half)
{
	if (a->array[0] <= pivot)
	{
		pb(a, b, 1);
		if (b->array[0] <= pivot_half)
			rb(b, 1);
	}
	else
		ra(a, 1);
}

static int	quick_sort(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	pivot_half;
	int	pivot;
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (a->size)
	{
		if (i == -1 || i == size)
		{
			i = 0;
			size = a->size;
			sorted = get_sorted_array(a);
			if (!sorted)
				return (0);
			pivot_half = get_pivot(a, sorted, (a->size / 10 + 15) / 2);
			pivot = get_pivot(a, sorted, a->size / 10 + 15);
			free(sorted);
		}
		push_to_b(a, b, pivot, pivot_half);
		i++;
	}
	return (1);
}

int	max_index(t_stack *b, int exception_index)
{
	int		index_max;
	int		max;
	int		i;

	max = b->array[0];
	index_max = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->array[i] > max && i != exception_index)
		{
			max = b->array[i];
			index_max = i;
		}
		i++;
	}
	return (index_max);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size > 10)
	{
		if (!quick_sort(a, b))
		{
			free_stacks(a, b);
			put_error("Memory allocation failed.");
		}
		insert_sort(a, b);
	}
	else
	{
		if (!sort_small(a, b))
		{
			free_stacks(a, b);
			put_error("Memory allocation failed.");
		}
	}
}
