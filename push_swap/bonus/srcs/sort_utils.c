/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:42:39 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 11:24:55 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     find_pos(t_stack *stack)
{
	int     pos;
	t_node  *temp;

	pos = 0;
	temp = stack->head;
	while (temp)
	{
		if (stack->head->value > temp->value)
			++pos;
		temp = temp->next;
	}
	return (pos);
}

void    change_pos(t_stack *stack)
{
	int pos;

	pos = find_pos(stack);
	if (!pos)
		return;
	else if (pos == 1)
		sa(stack);
	else if (pos == 2)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (pos == 3 && stack->size == 4)
		ra(stack);
	else if (pos == 3 && stack->size == 5)
	{
		rra(stack);
		sa(stack);
		ra(stack);
		ra(stack);
	}
	else
		ra(stack);
}

int     check_stack(t_stack *stack, int cnt, int pv)
{
	int i;
	t_node *cur;

	cur = stack->head;
	i = 0;
	while (i < cnt)
	{
		if (cur->value < pv)
			return (0);
		cur = cur->next;
		++i;
	}
	return (1);
}

void    find_pivot(t_stack *stack, int cnt, t_pivot *pivot)
{
	t_node *cur;
	int *arr;
	int i;

	i = 0;
	cur = stack->head;
	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		error();
	while (i < cnt && cur != NULL)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	sort(arr, cnt);
	pivot->first = arr[i / 3];
	pivot->second = arr[i * 2 / 3];
	free(arr);
}