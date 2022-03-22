/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:41:57 by jonghpar          #+#    #+#             */
/*   Updated: 2022/03/23 02:57:57 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    bubble_sort(int *arr, int cnt)
{
	int i;
	int j;
	int temp;

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

void    rreverse(t_stack *a, t_stack *b, int ra_cnt, int rb_cnt)
{
	int i;

	i = 0;
	while (i < ra_cnt && i < rb_cnt)
	{
		rrr(a, b);
		++i;
	}
	while (i < ra_cnt)
	{
		rra(a);
		++i;
	}
	while (i < rb_cnt)
	{
		rrb(b);
		++i;
	}
}

void    sort_lowcase(t_stack *a, t_stack *b, int cnt, int flag)
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

void    sort_b_to_a(t_stack *a, t_stack *b, int cnt)
{
	t_count count;
    t_pivot pivot;

	if (cnt <= 2)
		return (sort_lowcase(a, b, cnt, 0));
	init_count(&count);
	find_pv(b, cnt, &pivot);
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
	sort_a_to_b(a, b, count.pa - count.ra);
	rreverse(a, b, count.ra, count.rb);
	sort_a_to_b(a, b, count.ra);
	sort_b_to_a(a, b, count.rb);
}

void    sort_a_to_b(t_stack *a, t_stack *b, int cnt)
{
	t_count count;
    t_pivot pivot;

	if (cnt <= 2)
		return (sort_lowcase(a, b, cnt, 1));
	if (is_sorted(a, cnt) == 1)
		return;
	init_count(&count);
	find_pv(a, cnt, &pivot);
	while (cnt && !remain_all_big(a, cnt, pivot.second))
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
	rreverse(a, b, count.ra, count.rb);
	count.ra += cnt;
	sort_a_to_b(a, b, count.ra);
	sort_b_to_a(a, b, count.rb);
	sort_b_to_a(a, b, count.pb - count.rb);
}