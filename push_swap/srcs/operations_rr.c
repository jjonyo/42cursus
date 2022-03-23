/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:39:34 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 12:55:36 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rra(t_stack *stack)
{
	push_to_head(stack, pop_from_tail(stack));
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack *stack)
{
	push_to_head(stack, pop_from_tail(stack));
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	push_to_head(a, pop_from_tail(a));
	push_to_head(b, pop_from_tail(b));
	ft_putendl_fd("rrr", 1);
	return (1);
}
