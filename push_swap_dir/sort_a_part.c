/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:53:09 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:56:14 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_midd_nbr(int *a, int len, int stack)
{
	int	*sort;
	int i;
	int	ret;

	sort = new_int_tab(a);
	*sort = len;
	bubble_sort(sort);
	i = sort[0] / 2 + stack;
	if (sort[0] > i && i > 0)
		ret = sort[i];
	else
		ret = sort[sort[0] / 2 + 1];
	free(sort);
	return (ret);
}

int		find_instructions_a(int *a, int *b, char **str, int *midd)
{
	int	i;

	i = 1;
	if (a[1] < midd[0])
		ps_push_stack(a, b, str, "pb\n");
	else
	{
		midd[1]++;
		ps_rotate_stack(a, str, "ra\n");
	}
	while (a[0] > i - 1)
	{
		if (a[i] < midd[0])
			return (0);
		i++;
	}
	return (1);
}

void	sort_a_part(int *a, int *b, char **str, int *s)
{
	int	midd[4];
	int	size[2];

	midd[2] = *a == *s;
	midd[0] = find_midd_nbr(a, s[0], 1);
	midd[1] = 0;
	size[1] = *b;
	while (1)
	{
		if (check_if_sort_a(a, a[0]) && !if_b_has_a_part(a[1], b))
			break ;
		if (find_instructions_a(a, b, str, &midd[0]))
			break ;
	}
	size[1] = *b - size[1] > 0 ? *b - size[1] : *b;
	size[0] = s[0] - size[1];
	return_stack(a, str, &midd[0], "rra\n");
	try_rec(a, b, str, size);
	ps_swap_both(a, b, str, 'a');
	push_b_stack(a, b, str, &size[0]);
	s[0] = s[0] > *a ? *a : s[0];
	s[1] = s[1] > *b ? *b : s[1];
}
