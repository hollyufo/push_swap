/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:37:42 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 12:12:05 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack *stack)
{
	if (is_sorted_a(stack))
		return ;
	if (stack->a_size == 2)
		sort_2(stack);
	else if (stack->a_size == 3)
		sort_3(stack);
	else if (stack->a_size == 4)
		sort_4(stack);
	else if (stack->a_size == 5)
		sort_5(stack);
	else
		sort_large(stack);
}
