/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:33:27 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 13:38:22 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_range(t_stack *stack)
{
	int	size;
	int	range;

	size = stack->a_size;
	if (size >= 6 && size <= 18)
		range = 3;
	else if (size <= 100)
		range = 15;
	else if (size <= 500)
		range = 45;
	else
		range = 50;
	return (range);
}

void	sort_helper(int *i, int *range, t_stack *stack, int size)
{
	if (stack->b_size > 1)
		rb(stack, 1);
	if (*i < *range)
		*i += 1;
	if (*range < size - 1)
		*range += 1;
}

void	sort_helper2(int *i, int *range, t_stack *stack, int size)
{
	if (stack->b_size > 1 && stack->stack_b[0] < stack->stack_b[1])
		sb(stack, 1);
	if (*i < *range)
		*i += 1;
	if (*range < size - 1)
		*range += 1;
}

void	push_biggest_to_top_b(t_stack *stack)
{
	int	max_pos;
	int	i;

	if (stack->b_size <= 1)
		return ;
	max_pos = find_max_pos_b(stack);
	if (max_pos <= stack->b_size / 2)
	{
		i = 0;
		while (i < max_pos)
		{
			rb(stack, 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack->b_size - max_pos)
		{
			rrb(stack, 1);
			i++;
		}
	}
}
