/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:57:41 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 18:05:08 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_a(int *a, int *b, char **str)
{
	if (a[1] > a[2] && a[1] > a[3])
		ps_rotate_stack(a, str, "ra\n");
	if (a[1] > a[2])
		ps_swap_both(a, b, str, 'a');
	if (check_if_sort_a(a, *a) == 0)
		ps_rev_rotate_stack(a, str, "rra\n");
	if (check_if_sort_a(a, *a) == 0)
		ps_swap_both(a, b, str, 'a');
}

void	help_sort_four_a(int *a, int *b, char **str)
{
	int	*sort;
	int nbr[4];

	sort = bubble_sort(new_int_tab(a));
	nbr[0] = sort[2];
	nbr[1] = 0;
	nbr[2] = 1;
	nbr[3] = 0;
	if (sort[1] == a[4])
		ps_rev_rotate_stack(a, str, "rra\n");
	else if (sort[1] == a[2])
		ps_swap_both(a, b, str, 'a');
	free(sort);
	while (1)
	{
		if (check_if_sort_a(a, a[0]))
			break ;
		if (find_instructions_a(a, b, str, &nbr[0]))
			break ;
	}
}

void	sort_four_a(int *a, int *b, char **str)
{
	int 	f;

	f = 0;
	if (a[0] == 4)
	{
		help_sort_four_a(a, b, str);
		f = a[0] == 3 ? 1 : 0;
	}
	if (a[0] == 3 && check_if_sort_a(a, a[0]) == 0)
		sort_three_a(a, b, str);
	if (a[1] > a[2])
		ps_swap_stack(a, str, "sa\n");
	if (f)
		ps_push_stack(b, a, str, "pa\n");
}
/*
void	sort_three_b(int *a, int *b, char **str)
{
	if (b[1] < b[2] && b[1] < b[3])
		ps_rotate_stack(b, str, "rb\n");
	if (b[1] < b[2])
		ps_swap_both(a, b, str, 'b');
	if (check_if_sort_b(b, *b) == 0)
		ps_rev_rotate_stack(b, str, "rrb\n");
	if (check_if_sort_b(b, *b) == 0)
		ps_swap_both(a, b, str, 'b');
}

void	sort_five_b(int *a, int *b, char **str)
{
	int 	nbr[2];
	int 	*sort;

	if (b[0] == 4)
	{
		sort = bubble_sort(new_int_tab(b));
		nbr[0] = sort[4];
		if (sort[4] == b[4])
			ps_rev_rotate_stack(b, str, "rrb\n");
		free(sort);
		while (1)
		{
			if (find_instructions_b(a, b, str, &nbr[0]))
				break;
		}
	}
	if (b[0] == 3 && check_if_sort_b(b, b[0]) == 0)
		sort_three_b(a, b, str);
	if (b[1] < b[2])
		ps_swap_stack(b, str, "sb\n");
}*/
