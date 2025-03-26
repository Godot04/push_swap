/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:59:11 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 18:39:10 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_to_top(t_stack **a)
{
	while ((*a)->value != find_smallest(*a)->value)
	{
		if (find_smallest(*a)->is_below_medium == 0)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

int	count_stacks(t_stack *st)
{
	if (!st)
		return (0);
	int i = 0;
	while (st)
	{
		st = st->next;
		i++;
	}
	return (i);
}
