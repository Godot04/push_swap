/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:58:42 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 09:59:25 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *find)
{
	if (find == NULL)
		return (NULL);
	while (find->next != NULL)
		find = find->next;
	return (find);
}

t_stack	*find_highest(t_stack *find)
{
	if (find == NULL)
		return (NULL);
	t_stack *buff = find;
	t_stack *highest = find;
	while (buff)
	{
		if (buff->value > highest->value)
			highest = buff;
		buff = buff->next;
	}
	return (highest);
}

t_stack	*find_smallest(t_stack *find)
{
	if (find == NULL)
		return (NULL);
	t_stack *buff = find;
	t_stack *smallest = find;
	while (buff)
	{
		if (buff->value < smallest->value)
			smallest = buff;
		buff = buff->next;
	}
	return (smallest);
}

void	index_counter (t_stack *st)
{
	int i;
	int medium;

	if (st == NULL)
		return ;
	medium = count_stacks(st) / 2;
	i = 0;
	while (st)
	{
		st->index = i;
		if (i < medium)
			st->is_below_medium = 1;
		else
			st->is_below_medium = 0;
		st = st->next;
		i++;
	}
}
