/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_move_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:47:41 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/15 12:48:22 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	help_first_move_a(int i, int j, char **str, int *a)
{
	while (j > 0 && i < a[0] / 2)
	{
		ps_rotate_stack(a, str, "ra\n");
		j--;
	}
	while (j > a[0] / 2)
	{
		ps_rev_rotate_stack(a, str, "rra\n");
		j--;
	}
}

void	print_result(t_res last, int *f)
{
	ft_putstr(last.operations);
	if (f[2])
	{
		print_int_stack(last.stack);
		if (check_if_sort_a(last.stack, last.stack[0]))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	if (f[3] == 0)
	{
		ft_putstr("Number of instructions: ");
		ft_putnbr(last.size);
		ft_putchar('\n');
	}
	free(last.stack);
	ft_strdel(&(last.operations));
}

void	write_to_last(t_res *last, int new, char *str, int *a)
{
	if (last->operations)
	{
		free(last->stack);
		ft_strdel(&(last->operations));
	}
	last->size = new;
	last->stack = a;
	last->operations = str;
}

void	first_move_a(int argc, char **argv, int *flags, int *b)
{
	int		i;
	int		*a;
	char	*str;
	t_res	last;
	int		new;

	i = 0;
	last.size = INT_MAX;
	last.operations = NULL;
	while (i < argc)
	{
		str = ft_strdup("");
		a = make_tab(argc, argv);
		help_first_move_a(i, i, &str, a);
		if ((new = find_sort_algorithm(a, b, &str)) < last.size)
			write_to_last(&last, new, str, a);
		else
		{
			ft_strdel(&str);
			free(a);
		}
		i += argc > 150 ? argc : 1;
	}
	print_result(last, flags);
}
