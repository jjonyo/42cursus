/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:40:06 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 12:57:19 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_stack *stack)
{
	int	temp;

	if (stack->head == NULL || stack->head->next == NULL)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack *stack)
{
	int	temp;

	if (stack->head == NULL || stack->head->next == NULL)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (!(a->head == NULL || a->head->next == NULL))
	{
		temp = a->head->value;
		a->head->value = a->head->next->value;
		a->head->next->value = temp;
	}
	if (!(a->head == NULL || a->head->next == NULL))
	{
		temp = b->head->value;
		b->head->value = b->head->next->value;
		b->head->next->value = temp;
	}
	ft_putendl_fd("ss", 1);
	return (1);
}
