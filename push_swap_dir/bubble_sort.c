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

int 	*new_int_tab(int *tab)
{
	int 	*ret;
	int 	i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * (tab[0] + 1));
	while (i < tab[0] + 1)
	{
		ret[i] = tab[i];
		i++;
	}
	return (ret);
}

int		*bubble_sort(int *tab)
{
	int 	*sort;
	int 	end;
	int 	i;
	int 	start;

	end = 0;
	i = tab[0];
	sort = new_int_tab(tab);
	sort++;
	while (!end)
	{
		end = 1;
		start = 0;
		while (i - 1 > start)
		{
			if (sort[start] > sort[start + 1])
				end = 0;
			start++;
		}
	}
	sort--;
	return (sort);
}
