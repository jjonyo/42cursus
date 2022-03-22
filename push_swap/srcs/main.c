/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:40:39 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 02:40:49 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    create_stack(&a);
    create_stack(&b);
    parse(argc, argv, &a);
    push_swap(&a, &b);
    // print_stack(&a);
    clear_stack(&a, &b);
    return (0);
}