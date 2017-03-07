//
// Created by Denys on 01.03.2017.
//

#include "../Push_swap.h"

/*
int 	find_if_rr(int *a, int
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

int 	find_midd_nbr(int *a, int len)
{
	int 	*sort;
	int 	ret;

	sort = new_int_tab(a);
	*sort = len;
	sort = bubble_sort(sort);
	ret = sort[sort[0] / 2 + 1];
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

void	sort_a_part(int *a, int *b, char **str, int *s)
{
	int 	midd[3];
	int 	size[2];

	midd[2] = *a == *s;
	midd[0] = find_midd_nbr(a, s[0]);
	midd[1] = 0;
	size[1] = *b;
	while (1)
	{
//		if (check_if_sort_a(a, a[0]) && if_b_has_a_part(a[1], b))
//			break ;
		if (find_instructions(a, b, str, &midd[0]))
			break ;
	}
	size[0] = *a;
	size[1] = *b - size[1] > 0 ? *b - size[1] : *b;
	while (midd[1] && !midd[2])
	{
		ps_rev_rotate_stack(a, str, "rra\n");
		midd[1]--;
	}
	try_rec(a, b, str, size);
	ps_swap_both(a, b, str);
	while (size[1] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		size[1]--;
	}
}
