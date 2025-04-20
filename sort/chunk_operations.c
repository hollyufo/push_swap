/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:06:56 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 12:07:38 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_stack *stack)
{
	while (stack->b_size > 0)
	{
		push_biggest_to_top_b(stack);
		pa(stack, 1);
	}
}
