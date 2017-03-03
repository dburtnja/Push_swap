//
// Created by Denys on 01.03.2017.
//

#include "../Push_swap.h"

static int 	find_instructions(int *a, int *b, char **str, int *midd)
{
	int 	i;

	i = 1;
	if (b[1] > midd[0])
		ps_push_stack(b, a, str, "pa\n");
	else
	{
		midd[1]++;
		ps_rotate_stack(b, str, "rb\n");
	}
	while (b[0] > i - 1)
	{
		if (b[i] > midd[0])
			return (0);
		i++;
	}
	return (1);
}

void 	sort_b_part(int *a, int *b, char **str)
{
	int 	midd[2];

	midd[1] = 0;
	midd[0] = find_midd_nbr(b);
	while (1)
	{
		if (find_instructions(a, b, str, &midd[0]))
			break ;
	}
	while (midd[1])
	{
		ps_rev_rotate_stack(b, str, "rrb\n");
		midd[1]--;
	}
	try_rec(a, b, str);
	ps_swap_both(a, b, str);
	while (b[0] > 0) /// remove
		ps_push_stack(b, a, str, "pa\n");
	free(a);
}