
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
int						check_if_sort_a(int	*a, int len);
int						check_if_sort_b(int	*b, int len);
int						find_rr(int *tab, int nbr);

void					print_int_stack(int *a);
void					ps_swap_both(int *a, int *b, char **str);
void					ps_swap_stack(int *stack, char **str, char *s);
void					ps_rev_rotate_stack(int *arr, char **str, char *s);
void					ps_rotate_stack(int *arr, char **str, char *s);
void					ps_push_stack(int *from, int *into, char **str,
									  char *s);

void 					sort_b_part(int *a, int *b, char **str, int *s);
int 					find_midd_nbr(int *a, int len);
void					try_rec(int *a, int *b, char **str, int *s);
void					sort_a_part(int *a, int *b, char **str, int *s);
void					sort_three(int *a, int *b, char **str);
int 					if_b_has_a_part(int a, int *b);
int 					if_a_has_b_part(int b, int *a);
void					sort_four_a(int *a, int *b, char **str);
int 					find_instructions_a(int *a, int *b, char **str,
										   int *midd);


#endif
