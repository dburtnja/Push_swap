//
// Created by Denys Burtnjak on 3/9/17.
//

#include "../Push_swap.h"

void	rot_a_and_or_b(int *a, int *b, int *bul, char **str)
{
	if (bul[0] && bul[1])
	{
		ps_rotate_stack(a, str, "rr\n");
		ps_rotate_stack(b, str, "");
	}
	else
	{
		if (bul[0])
			ps_rotate_stack(a, str, "ra\n");
		if (bul[1])
			ps_rotate_stack(b, str, "rb\n");
	}
}

void	rev_rot_a_and_or_b(int *a, int *b, int *bul, char **str)
{
	if (bul[0] && bul[1])
	{
		ps_rev_rotate_stack(a, str, "rrr");
		ps_rev_rotate_stack(b, str, "\n");
	}
	else
	{
		if (bul[0])
			ps_rev_rotate_stack(a, str, "rra\n");
		if (bul[1])
			ps_rev_rotate_stack(b, str, "rrb\n");
	}
}

void	sort_three_a_full(int *a, int *b, int *s, char **str)
{
	int 	bul[2];

	bul[0] = s[0] == 3 && check_if_sort_a(a, s[0]) == 0;
	bul[1] = s[1] == 3 && check_if_sort_b(b, s[1]) == 0;
	ps_swap_both(a, b, str, 't');
	rot_a_and_or_b(a, b, &bul[0], str);
	ps_swap_both(a, b, str, 't');
	rev_rot_a_and_or_b(a, b, &bul[0], str);
	ps_swap_both(a, b, str, 't');
}