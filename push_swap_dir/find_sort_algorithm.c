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

int		find_instruction_a(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*a)->nbr < midd_nbr)
	{
		ps_push_stack(a, b);
		ft_putendl("pb");
		return (1);
	}
	if (rr)
	{
		ps_rev_rotate_stack(a);
		ft_putendl("rra");
	}
	else
	{
		ps_rotate_stack(a);
		ft_putendl("ra");
	}
	return (0);
}

void	dividing_lst_a(t_doub_lst **a, t_doub_lst *b)
{
	int 	midd_nbr;
	int 	size;


	size = (*a)->size / 2;
	midd_nbr = middle_nbr(*a, 0);
	//rr = if_rev_rotate(*a, midd_nbr, size);
	while (size > 0)
	{
		if (find_instruction_a(a, &b, midd_nbr, 0) == 1)
			size--;
	}
	find_sort_algorithm(a, &b); //if a sort - send NULL
	while (b)
	{
		ps_push_stack(&b, a);
		ft_putendl("pa");
	}
}

int		have_midd_nbr(t_doub_lst *lst, int midd_nbr)
{
	while (lst)
	{
		if (lst->nbr >= midd_nbr)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		find_instruction_b(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*b)->nbr >= midd_nbr) //if midd nbr only 1 finn it
	{
		ps_push_stack(b, a);
		ft_putendl("pa");
	}
	else if (rr)
	{
		ps_rev_rotate_stack(b);
		ft_putendl("rrb");
	}
	else if (!rr)
	{
		ps_rotate_stack(b);
		ft_putendl("rb");
	}
	return (have_midd_nbr(*b, midd_nbr) ? 0 : 1);
}

void	dividing_lst_b(t_doub_lst *a, t_doub_lst **b)
{
	int 	midd_nbr;
	int 	size;

	size = (*b)->size / 2;
	midd_nbr = middle_nbr(*b, 0);
	//rr = if_rev_rotate(*b, midd_nbr, size);
	while (size > 0)
	{
		if (find_instruction_b(&a, b, midd_nbr, 0))
			break ;
	}
	find_sort_algorithm(&a, b);
	while (a)
	{
		ps_push_stack(&a, b);
		ft_putendl("pb");
	}
}

void	find_sort_algorithm(t_doub_lst **a, t_doub_lst **b)
{
	sort_small(*a, *b);
	if (*a && (*a)->size > 2 && check_if_sort_a(*a) == 0)
		dividing_lst_a(a, NULL);
	if (*b && (*b)->size > 2 && check_if_sort_b(*b) == 0)
		dividing_lst_b(NULL, b);
}