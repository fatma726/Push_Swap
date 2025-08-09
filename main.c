/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:37:34 by fatmtahmdab       #+#    #+#             */
/*   Updated: 2025/08/10 00:55:44 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)// a.out
		return (0); //
	a.size_max = get_size_max(argv + 1, argc - 1);//بنحدد قيمه الحد الاقصي للستاك  a (اول ارجيومنت اسم البرنامج بعديه عشان كده ماينص ون )
	printf("%d\n", a.size_max);
	if (a.size_max <= 0)
        	return (0);// لو مفيش اي حاجه اليوزر دخلها اقفل البرنامج 
	a.array = malloc(sizeof(int) * a.size_max);// النقطه دي عشان اوصل لعنصر معين جوا الstruct 
	if (!a.array)// بعمل الوكيشن للarray
		put_error("Memory allocation failed.");
	a.size = 0;
	b.size_max = a.size_max;//خلي الحد الاقصي لده نفس ده // مجرد رقم بيقوله
	b.array = malloc(sizeof(int) * b.size_max);// بنحجز مكان الarray 
	if (!b.array)
	{
		free(a.array);
		put_error("Memory allocation failed.");
	}
	b.size = 0;
	parse(argv + 1, &a, &b);
	if (!is_sorted(&a, &b))
		sort(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
