/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:29:03 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 13:35:03 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	long			value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_pivot
{
	long	first;
	long	second;
}	t_pivot;

typedef struct s_count
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
}	t_count;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

void	create_stack(t_stack *stack);
void	init_count(t_count *count);
void	init_pivot(t_pivot *pivot);

int		pa(t_stack *to, t_stack *from);
int		pb(t_stack *to, t_stack *from);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *a, t_stack *b);

int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *a, t_stack *b);

int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *a, t_stack *b);

long	ft_atol(char **str);
int		is_integer(long num);
void	check_duplicate(t_stack *stack);
int		is_sorted(t_stack *stack, int count);
void	parse(int argc, char **argv, t_stack *a);

void	sort_arg_three(t_stack *stack);
void	sort_arg_under_three(t_stack *stack, int size);
void	sort_arg_five(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);

int		find_pos(t_stack *stack);
void	change_pos(t_stack *stack);
int		check_stack(t_stack *stack, int cnt, int pv);
void	find_pivot(t_stack *stack, int cnt, t_pivot *pivot);

void	sort(int *arr, int cnt);
void	undo_reverse(t_stack *a, t_stack *b, t_count *cnt, int check);
void	exit_case(t_stack *a, t_stack *b, int cnt, int flag);
void	sort_b_to_a(t_stack *a, t_stack *b, int cnt, int *check);
void	sort_a_to_b(t_stack *a, t_stack *b, int cnt, int *check);

void	push_to_tail(t_stack *stack, int value);
void	push_to_head(t_stack *stack, int value);
int		pop_from_head(t_stack *stack);
int		pop_from_tail(t_stack *stack);

void	print_stack(t_stack *stack);
void	error(void);
int		is_space(char c);
void	clear_stack(t_stack *a, t_stack *b);
#endif