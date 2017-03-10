/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:21:36 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 20:27:52 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	try_rec(int *a, int *b, char **str, int *s)
{
	if (a[0] <= 4 && a[0] > 2 && check_if_sort_a(a, a[0]) == 0)
		sort_four_a(a, b, str);//?????? ?????????? ????? ?
	if (s[0] <= 3 && s[1] <= 3)
		sort_three_a_full(a, b, s, str);
//	ps_swap_both(a, b, str, 'a');
	if (s[0] > 2 && check_if_sort_a(a, s[0]) == 0)
	{
	//	*str = ft_strjoin(*str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
		sort_a_part(a, b, str, s);
	}
//	if (b[0] <= 4 && check_if_sort_b(b, b[0]) == 0)
//		sort_five_b(a, b, str);
	if (s[0] <= 3 && s[1] <= 3)
		sort_three_a_full(a, b, s, str);
//	ps_swap_both(a, b, str, 'b');
	if (b[0] > 2 && s[1] > 2 && check_if_sort_b(b, s[1]) == 0)
	{
	//	*str = ft_strjoin(*str, "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
		sort_b_part(a, b, str, s);
	}
}
/*
void	move_to_a(int *a, int *b, char **str)
{
	int 	i;

	i = 2;
	while (b[0] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		ps_push_stack(b, a, str, "pa\n");
		i += 2;
		if (i % 4 == 0)
			ps_swap_both(a, b, str, 'a');
	}
}

void	non_rec_sort(int *a, int *b, char **str)
{
	move_to_b(a, b, str);
	move_to_a(a, b, str);
	if (check_if_sort_a(a, *a) == 0)
		ps_swap_stack(a, str, "sa\n");
}*/

void	find_sort_algorithm(int *a, int *b, char **str)
{
	int		size[2];
	int 	i;

	i = 0;
	size[0] = *a;
	size[1] = *b;
	try_rec(a, b, str, &size[0]);
	ft_putendl(*str);
	print_int_stack(a);
	print_int_stack(b);
	while (**str)
	{
		if (**str == '\n')
			i++;
		(*str)++;
	}
	if (check_if_sort_a(a, a[0]) && b[0] == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_putnbr(i);
	return ;
}