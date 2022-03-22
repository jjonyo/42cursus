/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:42:39 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 02:58:09 by jonghpar         ###   ########.fr       */
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

int     remain_all_big(t_stack *stack, int cnt, int pv)
{
	int i;
	t_node *temp;

	temp = stack->head;
	i = 0;
	while (i < cnt)
	{
		if (temp->value < pv)
			return (0);
		temp = temp->next;
		++i;
	}
	return (1);
}

void    find_pv(t_stack *stack, int cnt, t_pivot *pivot)
{
	t_node *temp;
	int *arr;
	int i;

	i = 0;
	temp = stack->head;
	arr = (int *)malloc(sizeof(int) * cnt);
	if (!arr)
		error();
	while (i < cnt && temp)
	{
		arr[i] = temp->value;
		temp = temp->next;
		++i;
	}
	bubble_sort(arr, cnt);
	pivot->first = arr[i / 3];
	pivot->second = arr[i * 2 / 3];
	free(arr);
}