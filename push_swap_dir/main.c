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
//                                   don't forget to add double check
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

int		check(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;
	int 		flags[2];

	flags[0] = 1;
	flags[1] = 1;
	b = NULL;
	if (argc > 1)
	{
	//	check_flag(&flags[0], &argv, &argc);
		a = make_lst(argc - 1, &argv[1]);
		if (check_instructions(&a, &b, &flags[0]) == 1)
			ft_putendl(flags[1] == 1 ? GREEN"OK"RESET : "OK");
		else
			ft_putendl(flags[1] == 1 ? RED"KO"RESET : "KO");
		free_lst(&a);
		if (b)
			free_lst(&b);
	}
	return 0;
}

int		main(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;
	char **temp = argv;
	int t = argc;

	b = NULL;
	if (argc > 1)
	{
		a = make_lst(argc - 1, &argv[1]);
		find_sort_algorithm(&a, &b);
	//	ft_putendl(check_if_sort_a(a) == 1 ? "OK" : "KO"); // remove before
	//	print_stacks(a, b, 0);// finish
		check(t, temp);
		free_lst(&a);
	}
	return 0;
}
