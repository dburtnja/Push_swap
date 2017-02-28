/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:20:58 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 20:21:06 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

int 	find_rr(int *tab, int nbr)
{
	int 	i;
	int 	first;
	int 	second;

	i = 1;
	while (tab[0] > i)
	{
		if (nbr > tab[i])
			first = i;
		i++;
	}
}

int		check_if_sort_a(int	*a)
{
	int 	i;

	i = 1;
	while (i + 1 < a[0])
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_if_sort_b(int *b)
{
	int 	i;

	i = 1;
	while (i + 1 < b[0])
	{
		if (b[i] < b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
