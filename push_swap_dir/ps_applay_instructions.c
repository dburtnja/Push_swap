/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_applay_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:50:07 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:52:56 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_swap_both(int *a, int *b, char **str, char o)
{
	int	a_bul;
	int	b_bul;

	a_bul = a[0] > 1 && a[1] > a[2];
	b_bul = b[0] > 1 && b[1] < b[2];
	if (a_bul && b_bul)
	{
		ps_swap_stack(a, str, "ss");
		ps_swap_stack(b, str, "\n");
	}
	else
	{
		if (a_bul && (o == 'a' || o == 't'))
			ps_swap_stack(a, str, "sa\n");
		if (b_bul && (o == 'b' || o == 't'))
			ps_swap_stack(b, str, "sb\n");
	}
}

void	ps_swap_stack(int *stack, char **str, char *s)
{
	int		buf;
	char	*b;

	b = ft_strjoin(*str, s);
	ft_strdel(str);
	*str = b;
	buf = stack[1];
	stack[1] = stack[2];
	stack[2] = buf;
}

void	ps_push_stack(int *from, int *into, char **str, char *s)
{
	char	*b;

	if (from[0] > 0)
	{
		b = ft_strjoin(*str, s);
		ft_strdel(str);
		*str = b;
		ft_memmove((void *)&into[2], (void *)&into[1],
				(sizeof(int) * into[0]));
		into[1] = from[1];
		into[0]++;
		from[0]--;
		ft_memmove((void *)&from[1], (void *)&from[2],
				(sizeof(int) * from[0]));
		from[from[0] + 1] = 0;
	}
}

void	ps_rotate_stack(int *arr, char **str, char *s)
{
	int		buf;
	char	*b;

	if (arr[0] > 0)
	{
		b = ft_strjoin(*str, s);
		ft_strdel(str);
		*str = b;
		buf = arr[1];
		ft_memmove((void *)&arr[1], (void *)&arr[2],
				(sizeof(int) * (arr[0] - 1)));
		arr[arr[0]] = buf;
	}
}

void	ps_rev_rotate_stack(int *arr, char **str, char *s)
{
	int		buf;
	char	*b;

	if (arr[0] > 0)
	{
		b = ft_strjoin(*str, s);
		ft_strdel(str);
		*str = b;
		buf = arr[arr[0]];
		ft_memmove((void *)&arr[2], (void *)&arr[1],
				(sizeof(int) * (arr[0] - 1)));
		arr[1] = buf;
	}
}
