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

#include "../push_swap.h"

void	try_rec(int *a, int *b, char **str, int *s)
{
	if (a[0] <= 4 && a[0] > 2 && check_if_sort_a(a, a[0]) == 0)
		sort_four_a(a, b, str);
	if (s[0] <= 3 && s[1] <= 3 && check_if_sort_a(a, s[0]) == 0)
		sort_three_a_full(a, b, s, str);
	if (s[0] > 2 && check_if_sort_a(a, s[0]) == 0)
		sort_a_part(a, b, str, s);
	ps_swap_both(a, b, str, 'a');
	if (b[0] > 2 && s[1] > 2 && check_if_sort_b(b, s[1]) == 0)
		sort_b_part(a, b, str, s);
}

int		nbr_of_operations(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return (i);
}

int		find_sort_algorithm(int *a, int *b, char **str)
{
	int		size[2];

	size[0] = *a;
	size[1] = *b;
	try_rec(a, b, str, &size[0]);
	return (nbr_of_operations(*str));
}
