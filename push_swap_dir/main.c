/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:22:09 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/27 16:44:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	if_same(int *tab)
{
	int 	i;
	int 	*sort;

	i = 0;
	sort = bubble_sort(tab);
	while (sort[0] > i)
	{
		if (sort[i] == sort[i + 1])
			error();
		i++;
	}
	free(sort);
}

int		check_if_num(char *str)
{
	int 	nbr;

	nbr = ft_atoi(str);
	if (ft_strcmp(ft_itoa(nbr), str) != 0)
		error();
	return (nbr);
}

int		*make_tab(int size, char **arg)
{
	int 	*tab;
	int 	i;

	tab = (int*)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (i < size)
	{
		tab[i] = check_if_num(arg[i]);
		i++;
	}
	if_same(tab);
	return (tab);
}

int		main(int argc, char **argv)
{
	int 	*a;
	int 	*b;

	b = NULL;
	if (argc > 1)
	{
		a = make_tab(argc - 1, argv + 1);
		//find_sort_algorithm(&a, &b);
		free(a);
	}
	return 0;
}
