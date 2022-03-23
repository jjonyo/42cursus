/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:46:21 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 15:57:22 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(char **str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (**str && !(**str == '+' || **str == '-') && !ft_isdigit(**str))
		error();
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		++(*str);
	}
	if (**str && !ft_isdigit(**str))
		error();
	while (ft_isdigit(**str))
	{
		num = (num * 10) + (**str - '0');
		++(*str);
	}
	num = (long)sign * num;
	return (num);
}

int	is_integer(long num)
{
	return (num <= MAX_INT && num >= MIN_INT);
}

void	check_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				error();
			temp = temp->next;
		}
		current = current->next;
	}
}

int	is_sorted(t_stack *stack, int count)
{
	int		i;
	t_node	*temp;

	temp = stack->head;
	i = 1;
	while (i++ < count)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	parse(int argc, char **argv, t_stack *a)
{
	int		i;
	long	num;
	char	*arg;

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			while (is_space(*arg))
				++arg;
			if (*arg == '\0')
				break ;
			num = ft_atol(&arg);
			if (!is_integer(num))
				error();
			push_to_tail(a, num);
		}
	}
	check_duplicate(a);
}
