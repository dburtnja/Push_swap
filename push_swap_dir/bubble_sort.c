/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:20:40 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 20:20:48 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

t_doub_lst	*bubble_sort(t_doub_lst *lst)
{
	int 		end;
	int 		buf;
	t_doub_lst	*p;

	end = 0;
	while (!end)
	{
		p = lst;
		end = 1;
		while (p->next)
		{
			if (p->nbr > p->next->nbr)
			{
				end = 0;
				buf = p->nbr;
				p->nbr = p->next->nbr;
				p->next->nbr = buf;
			}
			p = p->next;
		}
	}
	return (lst);
}
