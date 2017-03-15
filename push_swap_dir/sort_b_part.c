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

void	return_stack(int *stack, char **str, int *midd, char *operation)
{
	while (midd[1] && !midd[2])
	{
		ps_rev_rotate_stack(stack, str, operation);
		midd[1]--;
	}
}

void	push_b_stack(int *a, int *b, char **str, int *size)
{
	while (size[1] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		size[1]--;
	}
}

void	sort_b_part(int *a, int *b, char **str, int *s)
{
	int	midd[3];
	int	size[2];

	midd[2] = *b == s[1];
	midd[0] = find_midd_nbr(b, s[1], 0);
	midd[1] = 0;
	size[0] = *a;
	while (1)
	{
		if (find_instructions_b(a, b, str, &midd[0]))
			break ;
	}
	size[0] = *a - size[0] > 0 ? *a - size[0] : *a;
	size[1] = s[1] - size[0];
	return_stack(b, str, &midd[0], "rrb\n");
	try_rec(a, b, str, size);
	ps_swap_both(a, b, str, 'a');
	push_b_stack(a, b, str, &size[0]);
	s[0] += s[1];
	s[1] = 0;
}
