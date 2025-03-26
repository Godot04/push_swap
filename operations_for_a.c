/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:32:15 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:43:52 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*buff_b;
	t_stack	*target;
	long	index;

	target = NULL;
	while (a)
	{
		index = INT_MIN - 1;
		buff_b = b;
		while (buff_b)
		{
			if (buff_b->value < a->value && buff_b->value > index)
			{
				index = buff_b->value;
				target = buff_b;
			}
			buff_b = buff_b->next;
		}
		if (index == INT_MIN - 1)
			a->target = find_highest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	rotation_analysis(t_stack *a, t_stack *b)
{
	int	len_stack_a;
	int	len_stack_b;
	int	cost_a;
	int	cost_b;

	len_stack_a = count_stacks(a);
	len_stack_b = count_stacks(b);
	while (a)
	{
		if (a->is_below_medium == 1)
			cost_a = len_stack_a - a->index;
		else
			cost_a = a->index;
		if (a->target->is_below_medium == 0)
			cost_b = a->target->index;
		else
			cost_b = len_stack_b - a->target->index;
		if (a->is_below_medium == a->target->is_below_medium && cost_a && cost_b)
		{
			if (cost_a > cost_b)
				a->rotations = cost_a;
			else
				a->rotations = cost_b;
		}
		else
			a->rotations = cost_a + cost_b;
		a = a->next;
	}
}

void	move_stack_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *best_move_stack;
	int stack_a_down;
	int stack_b_down;

	best_move_stack = find_best_move_stack(*a);
	stack_a_down = best_move_stack->is_below_medium;
	stack_b_down = best_move_stack->target->is_below_medium;
	while(*a != best_move_stack && *b != best_move_stack->target && stack_a_down == stack_b_down)
	{
		if (stack_b_down)
			rrr(a, b);
		else
			rr(a, b);
	}
	while (*a != best_move_stack)
	{
		if (stack_a_down)
			rra(a, 1);
		else
			ra(a, 1);
	}
	while (*b != best_move_stack->target)
	{
		if (stack_b_down)
			rrb(b, 1);
		else
			rb(b, 1);
	}
	pb(a, b, 1);
}

void	operations_for_a(t_stack **a, t_stack **b, int st_len)
{
	while (st_len-- > 3 && stack_sorted(*a) == 1)
	{
		index_counter(*a);
		index_counter(*b);
		set_target_node_a(*a, *b);
		rotation_analysis(*a, *b);
		set_min_rotations(*a);
		move_stack_a_to_b(a, b);
	}
}
