/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:41:57 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 13:19:54 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(int *arr, int cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (j < cnt - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			++j;
		}
		++i;
	}
}

void	undo_reverse(t_stack *a, t_stack *b, t_count *cnt, int check)
{
	int	i;

	i = 0;
	if (check == 0)
	{
		while (i++ < cnt->rb)
			rrb(b);
		return ;
	}
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b);
		++i;
	}
	while (i < cnt->ra)
	{
		rra(a);
		++i;
	}
	while (i < cnt->rb)
	{
		rrb(b);
		++i;
	}
}

void	exit_case(t_stack *a, t_stack *b, int cnt, int flag)
{
	if (flag == 1 && cnt == 2)
	{
		if (a->head->value > a->head->next->value)
			sa(a);
	}
	if (flag == 0)
	{
		if (cnt == 1)
			pa(a, b);
		else if (cnt == 2)
		{
			if (b->head->value > b->head->next->value)
			{
				pa(a, b);
				pa(a, b);
			}
			else
			{
				sb(b);
				pa(a, b);
				pa(a, b);
			}
		}
	}
}

void	sort_b_to_a(t_stack *a, t_stack *b, int cnt, int *check)
{
	t_count	count;
	t_pivot	pivot;

	*check = 1;
	if (cnt <= 2)
		return (exit_case(a, b, cnt, 0));
	init_count(&count);
	find_pivot(b, cnt, &pivot);
	while (cnt--)
	{
		if (b->head->value < pivot.first)
			count.rb += rb(b);
		else
		{
			count.pa += pa(a, b);
			if (a->head->value < pivot.second)
				count.ra += ra(a);
		}
	}
	sort_a_to_b(a, b, count.pa - count.ra, check);
	undo_reverse(a, b, &count, *check);
	sort_a_to_b(a, b, count.ra, check);
	sort_b_to_a(a, b, count.rb, check);
}

void	sort_a_to_b(t_stack *a, t_stack *b, int cnt, int *check)
{
	t_count	count;
	t_pivot	pivot;

	exit_case(a, b, cnt, 1);
	if (is_sorted(a, cnt) == 1)
		return ;
	init_count(&count);
	find_pivot(a, cnt, &pivot);
	while (cnt && !check_stack(a, cnt, pivot.second))
	{
		if (a->head->value >= pivot.second)
			count.ra += ra(a);
		else
		{
			count.pb += pb(b, a);
			if (b->head->value >= pivot.first)
				count.rb += rb(b);
		}
		cnt--;
	}
	undo_reverse(a, b, &count, *check);
	count.ra += cnt;
	sort_a_to_b(a, b, count.ra, check);
	sort_b_to_a(a, b, count.rb, check);
	sort_b_to_a(a, b, count.pb - count.rb, check);
}
