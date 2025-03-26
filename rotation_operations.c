/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:57:48 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:34:09 by opopov           ###   ########.fr       */
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

void	find_best_move_choice(t_stack *st, int min_rotation)
{
	while (st)
	{
		if (min_rotation == st->rotations)
		{
			st->is_best_move_choice = 1;
			return ;
		}
		st = st->next;
	}
}

void	set_min_rotations(t_stack *st)
{
	int	min_rotation;
	t_stack *buff;

	if (!st)
		return ;
	buff = st;
	min_rotation = st->rotations;
	while (st)
	{
		if (st->rotations < min_rotation)
			min_rotation = st->rotations;
		st = st->next;
	}
	find_best_move_choice(buff, min_rotation);
}
