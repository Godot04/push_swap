/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:06:10 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 16:51:35 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **st)
{
	if (*st == NULL)
		return ;
	t_stack *s = *st;
	if (s->value > s->next->value)
		sa(st, 1);
}

void	sort_3(t_stack **st)
{
	if (*st == NULL)
		return ;
	t_stack *h = find_highest(*st);
	if (*st == h)
		ra(st, 1);
	else if((*st)->next == h)
		rra(st, 1);
	if ((*st)->value > (*st)->next->value)
		sa(st, 1);
}

void	sort_4_and_5(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	int pushed = count_stacks(*a) - 3;
	t_stack *smallest;
	while (pushed--)
	{
		smallest = find_smallest(*a);
		index_counter(*a);
		index_counter(*b);
		while ((*a)->value != smallest->value)
		{
			if (smallest->is_below_medium == 1)
				rra(a, 1);
			else
				ra(a, 1);
		}
		pb(a, b, 1);
	}
	sort_3(a);
	while (*b)
		pa(a, b, 1);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	st_len;

	st_len = count_stacks(*a);
	pb(a, b, 1);
	if (st_len-- > 3 && stack_sorted(*a) == 1)
		pb(a, b, 1);
	operations_for_a(a, b, st_len);
	sort_3(a);
	operations_for_b(a, b);
	index_counter(*a);
	small_to_top(a);
}
