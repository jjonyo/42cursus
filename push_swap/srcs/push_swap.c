/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:36:43 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 01:34:06 by jonghpar         ###   ########.fr       */
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

int pop_from_head(t_stack *stack)
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

int pop_from_tail(t_stack *stack)
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

void    check_duplicate(t_stack *stack)
{
    t_node *current;
    t_node *temp;

    current = stack->head;
    while (current)
    {
        temp = current->next;
        while (temp)
        {
            if (current->value == temp->value)
                error();
            temp = temp->next;
        }
        current = current->next;
    }
}

int is_sorted(t_stack *stack, int count)
{
	int     i;
    int     sorted;
	t_node  *temp;

	temp = stack->head;
	i = 1;
    sorted = 1;
	while (i++ < count)
	{
		if (temp->value > temp->next->value)
        {
            sorted = 0;
            break;
        }
		temp = temp->next;
	}
    if (sorted && stack->size == count)
        exit(0); //TODO : 스택 메모리 해제 필요할 수도
	return (sorted);
}

void    parse(int argc, char **argv, t_stack *a)
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
        push_to_tail(a, num);
    }
    check_duplicate(a);
    is_sorted(a, a->size);
}

int     main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    create_stack(&a);
    create_stack(&b);
    parse(argc, argv, &a);
    print_stack(&a);
    return (0);
}

