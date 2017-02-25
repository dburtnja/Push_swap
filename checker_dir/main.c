/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:11:24 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 19:11:35 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	error(void)
{
	ft_putendl(RED"Error"RESET);
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

void	check_flag(int *flag, char ***argv, int *argc)
{
	char	**p_argv;

	flag[0] = 0;
	flag[1] = 0;
	p_argv = *argv;
	p_argv++;
	(*argc)--;
	while (*argc > 1)
	{
		if (p_argv[0][0] == '-' && p_argv[0][1] == 'v')
			flag[0] = 1;
		else if (p_argv[0][0] == '-' && p_argv[0][1] == 'c')
			flag[1] = 1;
		else
			break ;
		(*argc)--;
		p_argv++;
	}
	*argv = p_argv;
}

int		main(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;
	int 		flags[2];

	b = NULL;
	if (argc > 1)
	{
		check_flag(&flags[0], &argv, &argc);
		a = make_lst(argc, &argv[0]);
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
