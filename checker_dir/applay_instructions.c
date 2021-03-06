/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applay_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:09:28 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/25 19:10:09 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_to_both(t_doub_lst **a, t_doub_lst **b, void (*f)(t_doub_lst**))
{
	f(a);
	f(b);
}

void	swap_stack(t_doub_lst **stack)
{
	int buf;

	if (*stack && (*stack)->size > 1)
	{
		buf = (*stack)->nbr;
		(*stack)->nbr = (*stack)->next->nbr;
		(*stack)->next->nbr = buf;
	}
}

void	push_stack(t_doub_lst **from, t_doub_lst **into)
{
	t_doub_lst	*p;

	if (*from && (*from)->size > 0)
	{
		p = *from;
		*from = (*from)->next;
		if (p->size > 1)
		{
			(*from)->prev = NULL;
			p->next->size = p->size - 1;
		}
		add_lst_to_front(into, p);
	}
}

void	rotate_stack(t_doub_lst **head)
{
	t_doub_lst	*front;

	if (*head && (*head)->size > 1)
	{
		front = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*head)->size = front->size;
		front->size = 0;
		front->next = NULL;
		add_lst_to_back(head, front);
	}
}

void	rev_rotate_stack(t_doub_lst **head)
{
	t_doub_lst	*p;
	t_doub_lst	*last;

	if (*head && (*head)->size > 1)
	{
		p = *head;
		while (p->next)
			p = p->next;
		last = p->prev;
		last->next = NULL;
		p->prev = NULL;
		(*head)->size--;
		add_lst_to_front(head, p);
	}
}
