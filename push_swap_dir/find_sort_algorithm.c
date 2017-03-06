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
	if (s[0] > 2 && check_if_sort_a(a, s[0]) == 0)
		sort_a_part(a, b, str, s);
	if (s[1] > 2 && check_if_sort_b(b, s[1]) == 0)
		sort_b_part(a, b, str, s);

}

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
			ps_swap_both(a, b, str);
	}
}

void	find_sort_algorithm(int *a, int *b, char **str)
{
//	move_to_b(a, b, str);
//	move_to_a(a, b, str);
//	if (check_if_sort_a(a) == 0)
//		ps_swap_stack(a, str, "sa\n");
	//rec
	int		size[2];
	int 	i;

	i = 0;
	size[0] = *a;
	size[1] = *b;
	try_rec(a, b, str, &size[0]);
	ft_putendl(*str);
	/*print_int_stack(a);
	print_int_stack(b);*/
	while (**str)
	{
		if (**str == '\n')
			i++;
		(*str)++;
	}
	if (check_if_sort_a(a, a[0]))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_putnbr(i);
	return ;
}