//
// Created by Denys on 27.02.2017.
//
#include "../Push_swap.h"

int		find_nbrs(t_doub_lst *lst)
{
	t_doub_lst	*sort_lst;
	t_doub_lst	*p;
	int 		nbr;

	sort_lst = bubble_sort(lst_dup(lst));
	p = sort_lst;
	while (p->next)
		p = p->next;
	nbr = p->prev->nbr;
	free_lst(&sort_lst);
	return (nbr);
}

int		find_instruction_b(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*b)->nbr >= midd_nbr)
	{
		ps_push_stack(b, a);
		ft_putendl("pa");
		return (1);
	}
	if (rr)
	{
		ps_rev_rotate_stack(b);
		ft_putendl("rrb");
	}
	else
	{
		ps_rotate_stack(b);
		ft_putendl("rb");
	}
	return (0);
}
void	swap_if_need(t_doub_lst *a, t_doub_lst *b)
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
void	find_operations(t_doub_lst **a, t_doub_lst **b)
{
	int 	midd_nbr;
	int 	size;
	int 	rr;

	size = 2;
	midd_nbr = find_nbrs(*b);
	rr = if_rev_rotate(*b, midd_nbr, size);
	while (size > 0)
	{
		if (find_instruction_b(a, b, midd_nbr, !rr))
			size--;
	}
	swap_if_need(*a, *b);
}

void	sort_b(t_doub_lst **a, t_doub_lst **b)
{
	while (*b)
	{
		find_operations(a, b);
		if (check_if_sort_b(*b))
			break ;
	}
	while (*b)
	{
		ps_push_stack(b, a);
		ft_putendl("pa");
	}
}
