/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:53:17 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 09:59:28 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*buff_a;
	t_stack	*target;
	long	index;

	while (b)
	{
		index = LONG_MAX;
		buff_a = a;
		while (buff_a)
		{
			if (buff_a->value > b->value && buff_a->value < index)
			{
				index = buff_a->value;
				target = buff_a;
			}
			buff_a = buff_a->next;
		}
		if (index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	move_stack_b_to_a(t_stack **a, t_stack **b)
{
	while (*a != (*b)->target)
	{
		if ((*b)->target->is_below_medium == 0)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pa(a, b, 1);
}

void	operations_for_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		index_counter(*a);
		index_counter(*b);
		set_target_node_b(*a, *b);
		move_stack_b_to_a(a, b);
	}
}
