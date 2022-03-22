/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:47:03 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 03:00:30 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print_stack(t_stack *stack)
{
    t_node *cur;
    
    printf("--------------------\n");
    cur = stack->head;
    while(cur)
    {
        printf("%ld ", cur->value);
        cur = cur->next;
    }
    printf("\n--------------------\n");
}

void    error()
{
    write(2, "Error\n", 6);
    exit(1);
}

int     is_space(char c)
{
    return c == ' ' || (9 <= c && c <= 13);
}


void    clear_stack(t_stack *a, t_stack *b)
{
    t_node *temp;
    t_node *del;

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