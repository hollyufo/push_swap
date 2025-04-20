/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:07:56 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 12:10:31 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	process_stack_a(t_stack *stack, int *arr, int *i, int *range)
{
	int	size;

	size = stack->a_size;
	while (stack->a_size > 0)
	{
		if (stack->stack_a[0] <= arr[*i])
		{
			pb(stack, 1);
			sort_helper(i, range, stack, size);
		}
		else if (stack->stack_a[0] <= arr[*range])
		{
			pb(stack, 1);
			sort_helper2(i, range, stack, size);
		}
		else
			ra(stack, 1);
	}
}

void	sort_large(t_stack *stack)
{
	int	*arr;
	int	i;
	int	range;
	int	size;

	size = stack->a_size;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	while (i < size)
	{
		arr[i] = stack->stack_a[i];
		i++;
	}
	sort_array(arr, size);
	range = get_range(stack);
	i = 0;
	process_stack_a(stack, arr, &i, &range);
	push_to_a(stack);
	free(arr);
}
