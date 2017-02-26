/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:22:09 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 22:01:50 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int		check_if_num(char *str)
{
	int 	nbr;

	nbr = ft_atoi(str);
	if (ft_strcmp(ft_itoa(nbr), str) != 0)
		error();
	return (nbr);
}

t_doub_lst	*make_lst(int size, char **arg)
{
	int			i;
	t_doub_lst	*p;
	t_doub_lst	*head;

	i = 0;
	head = NULL;
	while (i < size)
	{
		p = new_lst(check_if_num(arg[i]));
		add_lst_to_back(&head, p);
		i++;
	}
	head->size = size;
	return (head);
}

int		main(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;

	b = NULL;
	if (argc > 1)
	{
		a = make_lst(argc - 1, &argv[1]);
		find_sort_algorithm(&a, &b);
		ft_putendl(check_if_sort_a(a) == 1 ? "OK" : "KO");
		free_lst(&a);
	}
	return 0;
}
