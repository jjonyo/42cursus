/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:29:03 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/22 01:03:29 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_node
{
    long value;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

typedef struct s_stack
{
    int size;
    t_node *head;
    t_node *tail;    
}   t_stack;

typedef struct s_pivot
{
    long first;
    long second;
}   t_pivot;

typedef struct s_count
{
    int ra;
    int rb;
    int pa;
    int pb;
}   t_count;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

#endif