/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:48:40 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 15:14:54 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_sorted(t_stack *stack)
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
	count = count_total_numbers(ac, av);
	if (count <= 0)
		error();
	stack.stack_a = malloc(sizeof(int) * count);
	stack.stack_b = malloc(sizeof(int) * count);
	if (!stack.stack_a || !stack.stack_b)
		error();
	parse_args(&stack, ac, av);
	if (!is_sorted_a(&stack))
		sort_stack(&stack);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}

static int	count_numbers_in_arg(char *arg)
{
	char	**split_args;
	int		count;
	int		j;

	if (ft_strchr(arg, ' '))
	{
		split_args = ft_split(arg, ' ');
		if (!split_args)
			error();
		j = 0;
		while (split_args[j])
			j++;
		count = j;
		ft_free_split(split_args);
		return (count);
	}
	return (1);
}

int	count_total_numbers(int ac, char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		if (!av[i][0])
			error();
		count += count_numbers_in_arg(av[i]);
		i++;
	}
	return (count);
}
