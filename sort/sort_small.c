/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:14:28 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 13:47:35 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->a_size < 2)
		return ;
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack, 1);
}

void	sort_3(t_stack *stack)
{
	int	*stk;

	if (stack->a_size < 3)
		return ;
	stk = stack->stack_a;
	if (stk[1] > stk[0] && stk[1] > stk[2])
		rra(stack, 1);
	if (stk[1] > stk[0] && stk[1] > stk[2])
		sa(stack, 1);
	if (stk[0] > stk[1] && stk[0] > stk[2])
		ra(stack, 1);
	if (stk[0] > stk[1])
		sa(stack, 1);
}

void	sort_4(t_stack *stack)
{
	if (stack->a_size < 4)
		return ;
	move_min_to_top_a(stack);
	pb(stack, 1);
	sort_3(stack);
	pa(stack, 1);
}
