//
// Created by Denys on 01.03.2017.
//

#include "../Push_swap.h"

static int 	find_instructions(int *a, int *b, char **str, int *midd)
{
	int 	i;

	i = 1;
	if (b[1] >= midd[0])
		ps_push_stack(b, a, str, "pa\n");
	else
	{
		midd[1]++;
		ps_rotate_stack(b, str, "rb\n");
	}
	while (b[0] > i - 1)
	{
		if (b[i] >= midd[0])
			return (0);
		i++;
	}
	return (1);
}

void 	sort_b_part(int *a, int *b, char **str, int *s)
{
	int 	midd[3];
	int 	size[2];

	midd[2] = *b == s[1];
	midd[0] = find_midd_nbr(b, s[1]);
	midd[1] = 0;
	size[0] = *a;
	while (1)
	{
		if (find_instructions(a, b, str, &midd[0]))
			break ;
	}
	size[0] = *a - size[0] > 0 ? *a - size[0] : *a;
	size[1] = s[1] - size[0];
	while (midd[1] && !midd[2])
	{
		ps_rev_rotate_stack(b, str, "rrb\n");
		midd[1]--;
	}
	try_rec(a, b, str, size);
	ps_swap_both(a, b, str);
	while (size[1] > 0)
	{
		ps_push_stack(b, a, str, "pa\n");
		size[1]--;
	}
	s[1] = 0;
}