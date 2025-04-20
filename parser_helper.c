/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imchaibi <imchaibi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:55:43 by imchaibi          #+#    #+#             */
/*   Updated: 2025/04/20 15:21:48 by imchaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_token(char *token, t_stack *stack, int *pos)
{
	long	num;

	if (!check_digit(token))
		error();
	num = ft_atol(token);
	if (num == 2147483649)
		error();
	stack->stack_a[(*pos)++] = (int)num;
}

static void	process_split_arg(char *arg, t_stack *stack, int *pos)
{
	char	**split_args;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		error();
	j = 0;
	while (split_args[j])
	{
		process_token(split_args[j], stack, pos);
		j++;
	}
	ft_free_split(split_args);
}

static void	process_single_arg(char *arg, t_stack *stack, int *pos)
{
	process_token(arg, stack, pos);
}

static void	process_argument(char *arg, t_stack *stack, int *pos)
{
	if (!arg[0])
		error();
	if (ft_strchr(arg, ' '))
		process_split_arg(arg, stack, pos);
	else
		process_single_arg(arg, stack, pos);
}

void	parse_args(t_stack *stack, int ac, char **av)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < ac)
	{
		process_argument(av[i], stack, &pos);
		i++;
	}
	stack->a_size = pos;
	stack->b_size = 0;
	if (check_duplicates(stack))
		error();
}
