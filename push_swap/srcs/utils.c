/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:47:03 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 15:57:22 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

void	clear_stack(t_stack *a, t_stack *b)
{
	t_node	*temp;
	t_node	*del;

	temp = a->head;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
		del = NULL;
	}
	temp = b->head;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
		del = NULL;
	}
}
