/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:40:39 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 15:54:36 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	create_stack(&a);
	create_stack(&b);
	parse(argc, argv, &a);
	if (is_sorted(&a, a.size))
		return (0);
	push_swap(&a, &b);
	clear_stack(&a, &b);
	return (0);
}
