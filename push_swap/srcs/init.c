/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:45:07 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 12:54:27 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	init_count(t_count *count)
{
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
}

void	init_pivot(t_pivot *pivot)
{
	pivot->first = 0;
	pivot->second = 0;
}
