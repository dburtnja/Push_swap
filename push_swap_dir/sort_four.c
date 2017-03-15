/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:57:41 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/15 12:57:03 by dburtnja         ###   ########.fr       */
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
	int	f;

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
