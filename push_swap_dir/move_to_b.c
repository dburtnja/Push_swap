//
// Created by Denys on 28.02.2017.
//

#include "../Push_swap.h"

int		find_two_nbrs(int *tab)
{
	int 	i;
	int 	ret;
	int 	max;

	i = 1;
	ret = INT_MAX;
	max = INT_MAX;
	while (i < tab[0])
	{
		if (tab[i] < max)
			max = tab[i];
		i++;
	}
	i = 1;
	while (i < tab[0])
	{
		if (tab[i] < ret && tab[i] < max)
			ret = tab[i];
		i++;
	}
	return (ret);
}

int 	find_instruction(int *a, int *b, int nbr, int rr)
{
	char	*buf;


	if ()
}

void	move_nbrs(int *a, int *b, char **str)
{
	int		nbr;
	int 	i;
	int 	rr;

	nbr = find_two_nbrs(a);
	rr = find_rr(a, nbr);
	i = 2;
	while (i > 0 && a[0] > 3)
	{
		if (find_instruction(a, b, nbr, rr))
		{
			rr = find_rr(a, nbr);
			i--;
		}
	}

}

void	move_to_b(int *a, int *b, char **str)
{

	while (a[0] > 3 && check_if_sort_a(a) == 0)
	{
		move_nbrs(a, b, str);
	}
}