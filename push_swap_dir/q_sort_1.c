/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:22:48 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 21:07:27 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	sort_small(t_doub_lst *a, t_doub_lst *b)
{
	int		a_true;
	int 	b_true;

	a_true = (a && a->next && a->nbr > a->next->nbr && a->size > 1);
	b_true = (b && b->next && b->nbr < b->next->nbr && b->size > 1);
	if (a_true && b_true)
	{
		ps_apply_to_both(&a, &b, &ps_swap_stack);
		ft_putendl("ss");
	}
	if (a_true)
	{
		ps_swap_stack(&a);
		ft_putendl("sa");
	}
	if (b_true)
	{
		ps_swap_stack(&b);
		ft_putendl("sb");
	}
}

int 	middle_nbr(t_doub_lst *head)
{
	int 		i;
	t_doub_lst	*sort_lst;

	sort_lst = bubble_sort(lst_dup(head));
	i = head->size / 2;
	while (i > 0)
	{
		sort_lst = sort_lst->next;
		i--;
	}
	return (sort_lst->nbr);
}

int		if_rev_rotate(t_doub_lst *lst, int midd_nbr, int size)
{
	int 	left;
	int 	i;

	i = 0;
	left = 0;
	while (i < size)
	{
		if (midd_nbr > lst->nbr)
			left++;
		i++;
	}
	if (size - left > left)
		return (1);
	return (0);
}
