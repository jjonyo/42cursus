/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:36:43 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/22 01:51:30 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void     create_stack(t_stack *stack)
{
    if (!stack)
        return;
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

t_node      *create_node()
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = 0;
    return (new_node);
}

// void    add_node(t_stack **stack)
// {

// }

int     is_space(char c)
{
    return c == ' ' || (9 <= c && c <= 13);
}

void    error()
{
    write(2, "Error\n", 6);
    exit(1);
}

long    ft_atol(char **str)
{
    long    num;
    int     sign;

    num = 0;
    sign = 1;
    if (**str && !(**str == '+' || **str == '-') && !ft_isdigit(**str))
        error();
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign = -1;
        ++(*str);
    }
    if (**str && !ft_isdigit(**str))
        error();
    while (ft_isdigit(**str))
    {
        num = (num * 10) + (**str - '0');
        ++(*str);
    }
    num = (long)sign * num;
    return (num);
}

int     is_integer(long num)
{
    return (num <= MAX_INT && num >= MIN_INT);
}

void    parse(int argc, char **argv)
{
    int     i;
    long    num;
    char    *arg;
    
    i = 0;
    while (++i < argc)
    {
        arg = argv[i];
        while (is_space(*arg))
            ++arg;
        if (*arg == '\0')
            break;
        num = ft_atol(&arg);
        if (!is_integer(num))
            error();
    }
    //중복 체크
    //이미 정렬되었는지 체크
}

int     main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    create_stack(&a);
    create_stack(&b);
    parse(argc, argv);
    

    return (0);
}