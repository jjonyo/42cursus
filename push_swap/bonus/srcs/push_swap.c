/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:36:43 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 10:57:19 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_arg_three(t_stack *stack)
{
	int first;
	int second;
	int third;

	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (first < second && second < third)
		return;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first < second && second > third && first < third)
	{
		rra(stack);
		sa(stack);
	}
	else if (first > second && first > third && second < third)
		ra(stack);
	else if (first > second && second > third)
	{
		ra(stack);
		sa(stack);
	}
	else if (first < second && first > third && second > third)
		rra(stack);
}

void    sort_arg_under_three(t_stack *stack, int size)
{
	if (size <= 1)
		return;
	else if (size == 2)
    {
        if (stack->head->value > stack->head->next->value)
		    sa(stack);
    }
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
    int check;

    check = 0;
	if (a->size <= 3)
		sort_arg_under_three(a, a->size);
	else if (a->size == 5)
		sort_arg_five(a, b);
	else
		sort_a_to_b(a, b, a->size, &check);
}