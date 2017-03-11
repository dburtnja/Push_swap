/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:20:40 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:43:36 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*new_int_tab(int *tab)
{
	int	*ret;
	int	i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * (tab[0] + 1));
	while (i < tab[0] + 1)
	{
		ret[i] = tab[i];
		i++;
	}
	return (ret);
}

int		*bubble_sort(int *sort)
{
	int	end;
	int	buf;
	int	i;

	end = 0;
	sort++;
	while (!end)
	{
		end = 1;
		i = 0;
		while (i + 1 < sort[-1])
		{
			if (sort[i] > sort[i + 1])
			{
				end = 0;
				buf = sort[i];
				sort[i] = sort[i + 1];
				sort[i + 1] = buf;
			}
			i++;
		}
	}
	sort--;
	return (sort);
}
