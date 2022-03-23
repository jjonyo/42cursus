/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:40:39 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 11:58:54 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int     valid_operation(char *str)
{
    int	check;

	check = 0;
	if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n"))
	    check = 1;
	if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n"))
		check = 1;
	if (!ft_strcmp(str, "ss\n"))
		check = 1;
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n"))
		check = 1;
	if (!ft_strcmp(str, "rr\n"))
		check = 1;
	if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n"))
		check = 1;
	if (!ft_strcmp(str, "rrr\n"))
		check = 1;
	return (check);
}

void	execute_operation(t_stack *a, t_stack *b, char *oper)
{
	if (!ft_strncmp(oper, "pa\n", 3))
		pa(a, b);
	if (!ft_strncmp(oper, "pb\n", 3))
		pb(b, a);
	if (!ft_strncmp(oper, "sa\n", 3) || !ft_strncmp(oper, "ss\n", 3))
		sa(a);
	if (!ft_strncmp(oper, "sb\n", 3) || !ft_strncmp(oper, "ss\n", 3))
		sb(b);
	if (!ft_strncmp(oper, "ra\n", 3) || !ft_strncmp(oper, "rr\n", 3))
		ra(a);
	if (!ft_strncmp(oper, "rb\n", 3) || !ft_strncmp(oper, "rr\n", 3))
		rb(b);
	if (!ft_strncmp(oper, "rra\n", 4) || !ft_strncmp(oper, "rrr\n", 4))
		rra(a);
	if (!ft_strncmp(oper, "rrb\n", 4) || !ft_strncmp(oper, "rrr\n", 4))
		rrb(b);
}

void    do_operation(t_stack *a, t_stack *b, char *oper)
{
	int	check;

	check = valid_operation(oper);
	if (check)
		execute_operation(a, b, oper);
	else
	{
        clear_stack(a, b);
        error();
    }
}

int     main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char    *oper;

    if (argc < 2)
        return (0);
    create_stack(&a);
    create_stack(&b);
    parse(argc, argv, &a);
    while (1)
    {
        oper = get_next_line(1);
        if (!oper)
            break;
        do_operation(&a, &b, oper);
        free(oper);
    }
    if (is_sorted(&a, a.size) && b.size == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    clear_stack(&a, &b);
    return (0);
}