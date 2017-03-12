/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:22:09 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:48:58 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	if_same(int *tab)
{
	int	i;
	int	*sort;

	i = 0;
	sort = bubble_sort(new_int_tab(tab));
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
	int	nbr;

	nbr = ft_atoi(str);
	if (ft_strcmp(ft_itoa(nbr), str) != 0)
		error();
	return (nbr);
}

int		*make_tab(int size, char **arg)
{
	int	*tab;
	int	i;

	tab = (int*)malloc(sizeof(int) * (size + 1));
	i = 0;
	*tab = size;
	while (i < size)
	{
		tab[i + 1] = check_if_num(arg[i]);
		i++;
	}
	if_same(tab);
	return (tab);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*str;
	int		flags[5];

	b = (int*)ft_memalloc(sizeof(int) * (argc));
	str = ft_strdup("");
	if (argc > 1)
	{
		check_flag(&flags[0], &argv, &argc);
		a = make_tab(argc, argv);
		find_sort_algorithm(a, b, &str, &flags[0]);
		free(a);
	}
	free(b);
	ft_strdel(&str);
	return (0);
}
