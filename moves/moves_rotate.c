/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:05:38 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 12:06:39 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, int print)
{
	int	temp;
	int	i;

	if (stack->a_size <= 1)
		return ;
	temp = stack->stack_a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->a_size - 1] = temp;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack, int print)
{
	int	temp;
	int	i;

	if (stack->b_size <= 1)
		return ;
	temp = stack->stack_b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->b_size - 1] = temp;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rra(t_stack *stack, int print)
{
	int	temp;
	int	i;

	if (stack->a_size <= 1)
		return ;
	temp = stack->stack_a[stack->a_size - 1];
	i = stack->a_size - 1;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int print)
{
	int	temp;
	int	i;

	if (stack->b_size <= 1)
		return ;
	temp = stack->stack_b[stack->b_size - 1];
	i = stack->b_size - 1;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
