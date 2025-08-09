/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapfatoma.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:46:25 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/10 01:05:10 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack //هيكل 
{
	int	*array;// موشر لمصفوفه اعداد صحيحيه بخزن الارقام
	int	size; // عدد العناصر الحاليه
	int	size_max; // الحد الاقصي للي مممكن يشيله
}		t_stack;

typedef enum e_exec_state
{
	NORMAL,
	MINUS_ONE,
	MAX_AFTER_MINUS_ONE,
}		t_exec_state;

void	put_command(char *command_name);
void	sa(t_stack *a, int do_print);
void	sb(t_stack *b, int do_print);
void	pa(t_stack *a, t_stack *b, int do_print);
void	pb(t_stack *a, t_stack *b, int do_print);
void	ra(t_stack *a, int do_print);
void	rb(t_stack *b, int do_print);
void	rra(t_stack *a, int do_print);
void	rrb(t_stack *b, int do_print);
void	ss(t_stack *a, t_stack *b, int do_print);
void	rr(t_stack *a, t_stack *b, int do_print);
void	rrr(t_stack *a, t_stack *b, int do_print);
void	print_stacks(t_stack *a, t_stack *b);
int		get_size_max(char **str, int size);
int		is_duplicates(t_stack *a);
void	parse(char **strings, t_stack *a, t_stack *b);
int		*get_sorted_array(t_stack *stack);
void	insert_sort(t_stack *a, t_stack *b);
int		max_index(t_stack *b, int exception_index);
void	sort(t_stack *a, t_stack *b);
void	free_split(char **split);
void	put_error(char *error_msg);
int		is_digits(char *s);
void	free_stacks(t_stack *a, t_stack *b);
int		is_int(char *s);
int		is_sorted(t_stack *a, t_stack *b);
int		sort_small(t_stack *a, t_stack *b);
int		index_of(int *list, int size, int value);

#endif
