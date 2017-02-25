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

int		check_if_sort_a(t_doub_lst *a)
{
	a = a->next;
	while (a)
	{
		if (a->prev->nbr > a->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int		check_if_sort_b(t_doub_lst *b)
{
	b = b->next;
	while (b)
	{
		if (b->prev->nbr < b->nbr)
			return (0);
		b = b->next;
	}
	return (1);
}
