/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:48:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 14:58:35 by imchaibi         ###   ########.fr       */
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
	int		count;

	if (ac == 1)
		return (0);
	
	// First, count the total number of integers
	count = count_total_numbers(ac, av);
	if (count <= 0)
		error();
	
	// Allocate memory with the correct count
	stack.stack_a = malloc(sizeof(int) * count);
	stack.stack_b = malloc(sizeof(int) * count);
	if (!stack.stack_a || !stack.stack_b)
		error();
	
	// Parse arguments and fill the stack
	parse_args(&stack, ac, av);
	
	// Check if sorted and sort if needed
	if (!is_sorted_a(&stack))
		sort_stack(&stack);
	
	// Free memory
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}

// Function to count the total number of integers across all arguments
int	count_total_numbers(int ac, char **av)
{
	char	**split_args;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		if (!av[i][0])
			error();
		
		// Check if the argument contains spaces
		if (ft_strchr(av[i], ' '))
		{
			split_args = ft_split(av[i], ' ');
			if (!split_args)
				error();
			j = 0;
			while (split_args[j])
			{
				count++;
				j++;
			}
			ft_free_split(split_args);
		}
		else
			count++;
		i++;
	}
	return (count);
}