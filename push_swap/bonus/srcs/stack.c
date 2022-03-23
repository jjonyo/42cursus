/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:37:36 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 02:57:01 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_to_tail(t_stack *stack, int value)
{
    t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error();
	node->value = value;
	node->prev = stack->tail;
	if (stack->size == 0)
		stack->head = node;
	else
		stack->tail->next = node;
	node->next = NULL;
	stack->tail = node;
	++(stack->size);
}

void    push_to_head(t_stack *stack, int value)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error();
	node->value = value;
	node->next = stack->head;
	if (stack->size == 0)
		stack->tail = node;
	else
		stack->head->prev = node;
	node->prev = NULL;
	stack->head = node;
	++(stack->size);
}

int     pop_from_head(t_stack *stack)
{
	int     value;
	t_node  *node;

	if (stack->size == 0)
		error();
	node = stack->head;
	value = stack->head->value;
	stack->head = stack->head->next;
	free(node);
	if (stack->head == NULL)
		stack->tail = NULL;
	else
		stack->head->prev = NULL;
	--(stack->size);
	return (value);
}

int     pop_from_tail(t_stack *stack)
{
	int     value;
	t_node  *node;

	if (stack->size == 0)
		error();
	node = stack->tail;
	value = stack->tail->value;
	stack->tail = stack->tail->prev;
	free(node);
	if (stack->tail == NULL)
		stack->head = NULL;
	else
		stack->tail->next = NULL;
	--(stack->size);
	return (value);
}