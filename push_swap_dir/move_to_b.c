//
// Created by Denys on 28.02.2017.
//

#include "../Push_swap.h"

int		find_two_nbrs(int *tab)
{
	int 	i;
	int 	ret;
	int 	min;

	i = 1;
	ret = INT_MAX;
	min = INT_MAX;
	while (i - 1 < tab[0])
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	i = 1;
	while (i - 1 < tab[0])
	{
		if (tab[i] < ret && tab[i] > min)
			ret = tab[i];
		i++;
	}
	return (ret);
}

static int 	find_instruction(int *a, int *b, int *nbr, char **str)
{
	if (a[1] <= nbr[0])
	{
		ps_push_stack(a, b, str, "pb\n");
		return (1);
	}
	if (nbr[1] == 1)
		ps_rev_rotate_stack(a, str, "rra\n");
	else
		ps_rotate_stack(a, str, "ra\n");
	return (0);
}

void	move_nbrs(int *a, int *b, char **str)
{
	int		nbr[2];
	int 	i;

	nbr[0] = find_two_nbrs(a);
	nbr[1] = find_rr(a, nbr[0]);
	i = 2;
	while (i > 0 && a[0] > 3)
	{
		if (find_instruction(a, b, &nbr[0], str))
		{
			nbr[1] = find_rr(a, nbr[0]);
			i--;
		}
	}
}

void	sort_three(int *a, int *b, char **str)
{
	if (a[1] > a[2] && a[1] > a[3])
		ps_rotate_stack(a, str, "ra\n");
	if (a[1] > a[2])
		ps_swap_both(a, b, str);
	if (check_if_sort_a(a, *a) == 0)
		ps_rev_rotate_stack(a, str, "rra\n");
	if (check_if_sort_a(a, *a) == 0)
		ps_swap_both(a, b, str);
}

void	move_to_b(int *a, int *b, char **str)
{
	while (a[0] > 3 && check_if_sort_a(a, *a) == 0)
		move_nbrs(a, b, str);
	if (check_if_sort_a(a, *a) == 0 && a[0] == 3)
		sort_three(a, b, str);
	if (check_if_sort_a(a, *a) == 0)
		ps_swap_both(a, b, str);
}