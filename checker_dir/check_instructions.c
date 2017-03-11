/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 19:10:28 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/11 17:28:59 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_instruction(char *inst, t_doub_lst **a, t_doub_lst **b)
{
	if (ft_strcmp(inst, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(inst, "ss") == 0)
		apply_to_both(a, b, &swap_stack);
	else if (ft_strcmp(inst, "pa") == 0)
		push_stack(b, a);
	else if (ft_strcmp(inst, "pb") == 0)
		push_stack(a, b);
	else if (ft_strcmp(inst, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(inst, "rr") == 0)
		apply_to_both(a, b, &rotate_stack);
	else if (ft_strcmp(inst, "rra") == 0)
		rev_rotate_stack(a);
	else if (ft_strcmp(inst, "rrb") == 0)
		rev_rotate_stack(b);
	else if (ft_strcmp(inst, "rrr") == 0)
		apply_to_both(a, b, &rev_rotate_stack);
	else if (*inst != 0)
		error();
}

int		check_if_sort(t_doub_lst *a, t_doub_lst *b)
{
	t_doub_lst	*p;

	if (b)
		return (0);
	p = a->next;
	while (p)
	{
		if (p->prev->nbr > p->nbr)
			return (0);
		p = p->next;
	}
	return (1);
}

void	print_stacks(t_doub_lst *a, t_doub_lst *b, int flag, int fd)
{
	ft_putstr_fd(flag == 1 ? YELLOW"stack A:" : "stack A:", fd);
	while (a)
	{
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(a->nbr, fd);
		a = a->next;
	}
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(flag == 1 ? BLUE"stack B:" : "stack B:", fd);
	while (b)
	{
		ft_putchar_fd(' ', fd);
		ft_putnbr_fd(b->nbr, fd);
		b = b->next;
	}
	ft_putendl_fd(RESET"", fd);
}

void	apply_flags(t_doub_lst *a, t_doub_lst *b, int *flag, char *inst)
{
	if (flag[0] == 1 && inst && *inst != 0)
		print_stacks(a, b, flag[1], 1);
	if (flag[4] > 2 && inst && *inst != 0)
	{
		ft_putstr_fd("after: ", flag[4]);
		ft_putendl_fd(inst, flag[4]);
		print_stacks(a, b, flag[1], flag[4]);
	}
	if (inst && *inst != 0 && flag[3] >= 0)
		flag[3]++;
	ft_strdel(&inst);
}

int		check_instructions(t_doub_lst **a, t_doub_lst **b, int *flag)
{
	char	*inst;
	int		gnl_ret;

	if (flag[4] == 1)
		flag[4] = open("stacks.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	while ((gnl_ret = get_next_line(0, &inst)) > 0)
	{
		apply_instruction(inst, a, b);
		apply_flags(*a, *b, &flag[0], inst);
	}
	if (gnl_ret == -1)
		error();
	if (flag[2] && !flag[0])
		print_stacks(*a, *b, flag[1], 1);
	if (flag[3] >= 0)
	{
		ft_putstr("Number of instructions: ");
		ft_putnbr(flag[3]);
		ft_putchar('\n');
	}
	if (flag[4])
		close(flag[4]);
	if (inst)
		ft_strdel(&inst);
	return (check_if_sort(*a, *b));
}
