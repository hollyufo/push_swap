/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:00:00 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 12:04:42 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	temp;

	if (stack->a_size <= 1)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack, int print)
{
	int	temp;

	if (stack->b_size <= 1)
		return ;
	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	pa(t_stack *stack, int print)
{
	int	i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->a_size++;
	stack->b_size--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack, int print)
{
	int	i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->b_size++;
	stack->a_size--;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
