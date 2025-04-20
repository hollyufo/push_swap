#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <limits.h>
typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
}	t_stack;

void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack, int print);
void	pa(t_stack *stack, int print);
void	pb(t_stack *stack, int print);
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack, int print);
void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack, int print);

void	sort_stack(t_stack *stack);
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);
void	sort_large(t_stack *stack);

int		stack_size(t_stack *stack, char stack_name);
int		find_min_a(t_stack *stack);
int		find_max_a(t_stack *stack);
int		find_min_pos_a(t_stack *stack);
int		find_max_pos_b(t_stack *stack);
int		is_sorted_a(t_stack *stack);
int		get_range(t_stack *stack);
void	sort_helper(int *i, int *range, t_stack *stack, int size);
void	sort_helper2(int *i, int *range, t_stack *stack, int size);
void	push_biggest_to_top_b(t_stack *stack);
void	push_to_a(t_stack *stack);


void	parse_args(t_stack *stack, int ac, char **av);
void	process_args(t_stack *stack, int ac, char **av);
void	ft_free_split(char **split);
int		count_total_numbers(int ac, char **av);
void	move_min_to_top_a(t_stack *stack);
void	error(void);
int		check_digit(char *str);
int		check_duplicates(t_stack *stack);
long	ft_atol(char *str);
int		count_numbers_in_string(char *str);
#endif