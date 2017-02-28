
#ifndef CHECKER_CHECKER_H
# define CHECKER_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define INT_MIN		-2147483648
# define INT_MAX		2147483647
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define RED			"\x1b[31m"
# define RESET			"\x1b[0m"

typedef	struct			s_doub_lst
{
	int					nbr;
	int 				size;
	struct s_doub_lst	*next;
	struct s_doub_lst	*prev;
}						t_doub_lst;

t_doub_lst				*lst_dup(t_doub_lst *head);
t_doub_lst				*new_lst(int nbr);
void					add_lst_to_back(t_doub_lst **head, t_doub_lst *new);
void					add_lst_to_front(t_doub_lst **head, t_doub_lst *new);
void					free_lst(t_doub_lst **head);

int						*new_int_tab(int *tab);
int						*bubble_sort(int *tab);

void					error(void);
int						check_instructions(t_doub_lst **a, t_doub_lst **b,
											  int *flag);
void					swap_stack(t_doub_lst **stack);
void					push_stack(t_doub_lst **from, t_doub_lst **into);
void					rotate_stack(t_doub_lst **head);
void					rev_rotate_stack(t_doub_lst **head);
void					apply_to_both(t_doub_lst **a, t_doub_lst **b,
									   void (*f)(t_doub_lst **stack));
void					print_stacks(t_doub_lst *a, t_doub_lst *b, int flag);


void					find_sort_algorithm(int *a, int *b, char **str);
void					move_to_b(int *a, int *b, char **str);
int						check_if_sort_a(int	*a);
int						check_if_sort_b(int	*b);
int						find_rr(int *tab, int nbr);


#endif
