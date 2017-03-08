//
// Created by Denys Burtnjak on 3/8/17.
//

#include "../Push_swap.h"

void	sort_three_a(int *a, int *b, char **str)
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

void	sort_four_a(int *a, int *b, char **str)
{
	int 	f;

	f = 0;
	if (a[0] == 4)
	{
		f = 1;

		while (1)
		{
			if (check_if_sort_a(a, a[0]))
				return ;
			if ()
		}
	}
	if (a[0] == 3)
		sort_three_a(a, b, str);
	if (a[1] > a[2])
		ps_swap_stack(a, str, "sa\n");
	if (f)
		ps_push_stack(b, a, str, "pa\n");
}