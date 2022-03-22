/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:36:43 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 03:00:11 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_arg_three(t_stack *stack)
{
	int bot;
	int mid;
	int top;

	bot = stack->head->value;
	mid = stack->head->next->value;
	top = stack->head->next->next->value;
	if (bot < mid && mid < top)
		return;
	if (bot > mid && mid < top && bot < top)
		sa(stack);
	else if (bot < mid && mid > top && bot < top)
	{
		rra(stack);
		sa(stack);
	}
	else if (bot > mid && bot > top && mid < top)
		ra(stack);
	else if (bot > mid && mid > top)
	{
		ra(stack);
		sa(stack);
	}
	else if (bot < mid && bot > top && mid > top)
		rra(stack);
}

void    sort_arg_under_three(t_stack *stack, int size)
{
	if (size <= 1)
		return;
	else if (size == 2 && stack->head->value > stack->head->next->value)
		sa(stack);
	else if (size == 3)
		sort_arg_three(stack);
	else
		return;
}

void    sort_arg_five(t_stack *a, t_stack* b)
{
    pb(b, a);
	pb(b, a);
	sort_arg_three(a);
	pa(a, b);
	change_pos(a);
	pa(a, b);
	change_pos(a);
}

void    push_swap(t_stack *a, t_stack *b)
{
	if (a->size < 4)
		sort_arg_under_three(a, a->size);
	else if (a->size == 5)
		sort_arg_five(a, b);
	else
		sort_a_to_b(a, b, a->size);
}