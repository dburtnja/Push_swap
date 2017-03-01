//
// Created by Denys on 01.03.2017.
//

#include "../Push_swap.h"

/*
int 	find_if_rr(int *a, int midd)
{
	int 	i;
	int 	left;
	int 	right;

	i = 1;
	left = 0;
	right = 0;
	while (i - 1 < a[0])
	{
		if (a[i] > midd && a[0] / 2 > i)
			left++;
		else if (a[i] > midd)
			right++;
		i++;
	}
	if
}
*/

int 	find_midd_nbr(int *a)
{
	int 	*sort;
	int 	ret;

	sort = bubble_sort(new_int_tab(a));
	ret = sort[sort[0] / 2];
	free(sort);
	return (ret);
}

static int 	find_instructions(int *a, int *b, char **str, int *midd)
{
	int 	i;

	i = 1;
	if (a[1] < midd[0])
		ps_push_stack(a, b, str, "pb\n");
	else
	{
		midd[1]++;
		ps_rotate_stack(a, str, "ra\n");
	}
	while (a[0] > i - 1)
	{
		if (a[i] < midd[0])
			return (0);
		i++;
	}
	return (1);
}

void	sort_a_part(int *a, int *b, char **str)
{
	int 	midd[2];

	midd[0] = find_midd_nbr(a);
	midd[1] = 0;
	while (1)
	{
		if (find_instructions(a, b, str, &midd[0]))
			break ;
	}
	while (midd[1])
	{
		ps_rev_rotate_stack(a, str, "rra\n");
		midd[1]--;
	}
	try_rec(a, b, str);
}