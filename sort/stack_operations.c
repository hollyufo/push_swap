/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:36:02 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 13:36:07 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack *stack, char stack_name)
{
	if (stack_name == 'a')
		return (stack->a_size);
	return (stack->b_size);
}

int	find_min_a(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->a_size == 0)
		return (0);
	min = stack->stack_a[0];
	i = 1;
	while (i < stack->a_size)
	{
		if (stack->stack_a[i] < min)
			min = stack->stack_a[i];
		i++;
	}
	return (min);
}

int	find_max_a(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->a_size == 0)
		return (0);
	max = stack->stack_a[0];
	i = 1;
	while (i < stack->a_size)
	{
		if (stack->stack_a[i] > max)
			max = stack->stack_a[i];
		i++;
	}
	return (max);
}

int	find_min_pos_a(t_stack *stack)
{
	int	min;
	int	min_pos;
	int	i;

	if (stack->a_size == 0)
		return (0);
	min = stack->stack_a[0];
	min_pos = 0;
	i = 1;
	while (i < stack->a_size)
	{
		if (stack->stack_a[i] < min)
		{
			min = stack->stack_a[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	find_max_pos_b(t_stack *stack)
{
	int	max;
	int	max_pos;
	int	i;

	if (stack->b_size == 0)
		return (0);
	max = stack->stack_b[0];
	max_pos = 0;
	i = 1;
	while (i < stack->b_size)
	{
		if (stack->stack_b[i] > max)
		{
			max = stack->stack_b[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
