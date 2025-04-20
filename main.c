/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:48:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 14:51:21 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_stack_sorted(t_stack *stack)
{
    for (int i = 0; i < stack->a_size - 1; i++)
    {
        if (stack->stack_a[i] > stack->stack_a[i + 1])
            return (0);
    }
    return (1);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		*stack_a;
	int		*stack_b;

    if (ac == 1)
    {
        return (0);
    }
	
    stack_a = malloc(sizeof(int) * (ac - 1));
	stack_b = malloc(sizeof(int) * (ac - 1));
	if (!stack_a || !stack_b)
		error();
	stack.stack_a = stack_a;
	stack.stack_b = stack_b;
	parse_args(&stack, ac, av);
	if (!is_sorted_a(&stack))
	    sort_stack(&stack);
	free(stack_a);
	free(stack_b);
	return (0);
}