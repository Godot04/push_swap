/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:57:48 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 20:46:20 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*find_best_move_stack(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st)
	{
		if (st->is_best_move_choice == 1)
			return (st);
		st = st->next;
	}
	return (NULL);
}

void	set_min_rotations(t_stack *st)
{
	long	min_rotation;
	t_stack	*buff;

	if (!st)
		return ;
	min_rotation = LONG_MAX;
	buff = st;
	while (st)
	{
		if (st->rotations < min_rotation)
		{
			min_rotation = st->rotations;
			buff = st;
		}
		st = st->next;
	}
	buff->is_best_move_choice = 1;
}
