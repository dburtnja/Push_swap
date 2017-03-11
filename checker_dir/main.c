/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:11:24 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:22:38 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void		if_same(int nbr, t_doub_lst *lst)
{
	while (lst)
	{
		if (lst->nbr == nbr)
			error();
		lst = lst->next;
	}
}

int			check_if_num(char *str)
{
	int	nbr;

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
		if_same(p->nbr, head);
		add_lst_to_back(&head, p);
		i++;
	}
	if (head == NULL)
		return (0);
	head->size = size;
	return (head);
}

int			main(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;
	int			flags[5];

	b = NULL;
	if (argc > 1)
	{
		check_flag(&flags[0], &argv, &argc);
		a = make_lst(argc, &argv[0]);
		//if (check_instructions(&a, &b, &flags[0]) == 1)
	//		ft_putendl(flags[1] == 1 ? GREEN"OK"RESET : "OK");
	//	else
	//		ft_putendl(flags[1] == 1 ? RED"KO"RESET : "KO");
		//free_lst(&a);
		free(a);
		if (b)
			free_lst(&b);
	}
	return (0);
}
