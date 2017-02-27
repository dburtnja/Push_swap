//
// Created by Denys on 27.02.2017.
//

#include "../Push_swap.h"

int		find_instruction_a(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int
*rr)
{
	if ((*a)->nbr < midd_nbr)
	{
		ps_push_stack(a, b);
		ft_putendl("pb");
		return (1);
	}
	rr[1]++;
	if (rr[0])
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

void	sort_a(t_doub_lst **a, t_doub_lst *b)
{
	int 	midd_nbr;
	int 	size;
	int		rr[2];

	size = (*a)->size / 2;
	midd_nbr = middle_nbr(*a, 0);
	rr[0] = if_rev_rotate(*a, midd_nbr, size);
	rr[1] = 0;
	while (size > 0)
	{
		if (find_instruction_a(a, &b, midd_nbr, &rr[0]) == 1)
			size--;
	}
	while (rr[1] > 0)
	{
		if (!rr[0])
		{
			ps_rev_rotate_stack(a);
			ft_putendl("rra");
		}
		else
		{
			ps_rotate_stack(a);
			ft_putendl("ra");
		}
		rr[1]--;
	}
	find_sort_algorithm(a, &b);
	while (b)
	{
		ps_push_stack(&b, a);
		ft_putendl("pa");
	}

}

void	find_sort_algorithm(t_doub_lst **a, t_doub_lst **b)
{
	sort_small(*a, *b);
	if (*a && (*a)->size > 2 && check_if_sort_a(*a) == 0)
		sort_a(a, NULL);
	if (*b && (*b)->size > 2)
		sort_b(a, b);
}