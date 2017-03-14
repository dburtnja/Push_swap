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

int		find_rr(int *a, int midd)
{
	int	i;
	int	left;
	int	right;

	i = 1;
	left = 0;
	right = 0;
	while (i - 1 < a[0])
	{
		if (a[i] > midd && left == 0)
			left = i;
		else if (a[i] > midd)
			right = i + 1;
		i++;
	}
	if (left <= right)
		return (0);
	return (1);
}

int		find_midd_nbr(int *a, int len, int stack)
{
	int	*sort;
	int i;
	int	ret;

	sort = new_int_tab(a);
	*sort = len;
	bubble_sort(sort);
	i = sort[0] / 2 + (stack ? 1 : 0);
	ret = sort[i];
	free(sort);
	return (ret);
}

int		find_instructions_a(int *a, int *b, char **str, int *midd)
{
	int	i;

	i = 1;
	if (a[1] < midd[0])
		ps_push_stack(a, b, str, "pb\n");
	else if (midd[2] && midd[3])
		ps_rev_rotate_stack(a, str, "rra\n");
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
	midd[3] = 0;
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
	while (midd[1] && !midd[2])
	{
		ps_rev_rotate_stack(a, str, "rra\n");
		midd[1]--;
	}
	try_rec(a, b, str, size);
	if (s[0] > *a)
		s[0] = *a;
	if (s[1] > *b)
		s[1] = *b;
	while (size[1] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		size[1]--;
	}
}
