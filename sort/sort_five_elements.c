/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:11:21 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 13:40:48 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_min_to_top_a(t_stack *stack)
{
	int	min_pos;
	int	i;

	min_pos = find_min_pos_a(stack);
	if (min_pos <= stack->a_size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(stack, 1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stack->a_size - min_pos)
		{
			rra(stack, 1);
			i++;
		}
	}
}

void	sort_5(t_stack *stack)
{
	if (stack->a_size < 5)
		return ;
	move_min_to_top_a(stack);
	pb(stack, 1);
	sort_4(stack);
	pa(stack, 1);
}
