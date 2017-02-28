/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:21:36 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 20:27:52 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Push_swap.h"

void	find_sort_algorithm(t_doub_lst **a, t_doub_lst **b)
{
	sort_small(*a, *b);
	if (*a && (*a)->size > 2 && check_if_sort_a(*a) == 0)
		sort_a(a, NULL);
	if (*b && (*b)->size > 2)
		sort_b(a, b);
}