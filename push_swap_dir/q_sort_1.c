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

	a_true = (a && a->next && a->nbr > a->next->nbr && a->size == 2);
	b_true = (b && b->next && b->nbr < b->next->nbr && b->size == 2);
	if (a_true && b_true)
	{
		ps_apply_to_both(&a, &b, &ps_swap_stack);
		ft_putendl("ss");
	}
	else if (a_true)
	{
		ps_swap_stack(&a);
		ft_putendl("sa");
	}
	else if (b_true)
	{
		ps_swap_stack(&b);
		ft_putendl("sb");
	}
}

int 	middle_nbr(t_doub_lst *head, int f)
{
	int 		i;
	t_doub_lst	*sort_lst;
	t_doub_lst	*p;

	sort_lst = bubble_sort(lst_dup(head));
	i = head->size / 2 - (f && head->size % 2 == 0 ? 1 : 0);
	p = sort_lst;
	while (i > 0)
	{
		p = p->next;
		i--;
	}
	i = p->nbr;
	free_lst(&sort_lst);
	return (i);
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
