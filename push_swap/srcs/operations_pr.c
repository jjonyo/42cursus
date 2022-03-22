/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:38:18 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 02:38:26 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     pa(t_stack *to, t_stack *from)
{
	if (from->head == NULL)
		return (0);
	push_to_head(to, pop_from_head(from));
	ft_putendl_fd("pa", 1);
	return (1);
}

int     pb(t_stack *to, t_stack *from)
{
	if (from->head == NULL)
		return (0);
	push_to_head(to, pop_from_head(from));
	ft_putendl_fd("pb", 1);
	return (1);
}

int     ra(t_stack *stack)
{
	push_to_tail(stack, pop_from_head(stack));
	ft_putendl_fd("ra", 1);
	return (1);
}

int     rb(t_stack *stack)
{
	push_to_tail(stack, pop_from_head(stack));
	ft_putendl_fd("rb", 1);
	return (1);
}

int     rr(t_stack *a, t_stack *b)
{
	push_to_tail(a, pop_from_head(a));
	push_to_tail(b, pop_from_head(b));
	ft_putendl_fd("rr", 1);
	return (1);
}