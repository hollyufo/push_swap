/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:27:00 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 15:08:58 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_size)
	{
		j = i + 1;
		while (j < stack->a_size)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (2147483649);
		i++;
	}
	return (result * sign);
}

void	init_stack(t_stack *stack, char **av)
{
	int		i;
	long	num;

	i = 0;
	while (av[i])
	{
		if (!check_digit(av[i]))
			error();
		num = ft_atoi(av[i]);
		if (num == 2147483649)
			error();
		stack->stack_a[i] = (int)num;
		i++;
	}
	stack->a_size = i;
	stack->b_size = 0;
	if (check_duplicates(stack))
		error();
}

void	parse_args(t_stack *stack, int ac, char **av)
{
	char	**split_args;
	int		i;
	int		j;
	int		pos;
	long	num;

	i = 1;
	pos = 0;
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
				if (!check_digit(split_args[j]))
				{
					ft_free_split(split_args);
					error();
				}
				num = ft_atol(split_args[j]);
				if (num == 2147483649)
				{
					ft_free_split(split_args);
					error();
				}
				stack->stack_a[pos++] = (int)num;
				j++;
			}
			ft_free_split(split_args);
		}
		else
		{
			if (!check_digit(av[i]))
				error();
			num = ft_atol(av[i]);
			if (num == 2147483649)
				error();
			stack->stack_a[pos++] = (int)num;
		}
		i++;
	}
	stack->a_size = pos;
	stack->b_size = 0;
	if (check_duplicates(stack))
		error();
}

// Helper function to free split result
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}