//
// Created by Denys Burtnjak on 3/9/17.
//

#include "../Push_swap.h"

void	rot_a_and_or_b(int *a, int *b, int *s, char **str)
{

}

void	sort_three_a_full(int *a, int *b, int *s, char **str)
{
	int 	bul[2];

	bul[0] = s[0] == 3 && check_if_sort_a(a, s[0]);
	bul[1] = s[1] == 3 && check_if_sort_b(b, s[1]);
	ps_swap_both(a, b, str, 't');




	if (a[1] > a[2])
		ps_rotate_stack(a, str, "ra\n");
	if (a[1] > a[2])
		ps_swap_both(a, b, str, 'a');
	if (check_if_sort_a(a, *a) == 0)
		ps_rev_rotate_stack(a, str, "rra\n");
	if (check_if_sort_a(a, *a) == 0)
		ps_swap_both(a, b, str, 'a');
}