/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:20:58 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/15 12:54:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_int_stack(int *a)
{
	int	i;

	i = 1;
	while (a[0] > i - 1)
	{
		ft_putchar(' ');
		ft_putnbr(a[i]);
		i++;
	}
	ft_putendl("");
}

int		check_if_sort_a(int *a, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_if_sort_b(int *b, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (b[i] < b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		if_b_has_a_part(int a, int *b)
{
	int	i;

	i = 1;
	while (i <= b[0])
	{
		if (a < b[i])
			return (1);
		i++;
	}
	return (0);
}
