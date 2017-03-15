/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:56:28 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:57:34 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_instructions_b(int *a, int *b, char **str, int *midd)
{
	int	i;

	i = 1;
	if (b[1] > midd[0])
		ps_push_stack(b, a, str, "pa\n");
	else
	{
		midd[1]++;
		ps_rotate_stack(b, str, "rb\n");
	}
	while (b[0] > i - 1)
	{
		if (b[i] > midd[0])
			return (0);
		i++;
	}
	return (1);
}

void	sort_b_part(int *a, int *b, char **str, int *s)
{
	int	midd[3];
	int	size[2];

	midd[2] = *b == s[1];
	midd[0] = find_midd_nbr(b, s[1], 1); //b[0] % 2 ? 0 : 1
	midd[1] = 0;
	size[0] = *a;
	while (1)
	{
	//	if (check_if_sort_b(b, b[0]) && !if_a_has_b_part(b[1], a))
	//		break ;
		if (find_instructions_b(a, b, str, &midd[0]))
			break ;
	}
	size[0] = *a - size[0] > 0 ? *a - size[0] : *a;
	size[1] = s[1] - size[0];
	while (midd[1] && !midd[2])
	{
		ps_rev_rotate_stack(b, str, "rrb\n");
		midd[1]--;
	}
	try_rec(a, b, str, size);
	ps_swap_both(a, b, str, 'a');
	while (size[1] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		size[1]--;
	}
	s[0] += s[1];
	s[1] = 0;
}
