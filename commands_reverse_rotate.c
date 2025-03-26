/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:13 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:15:48 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra (t_stack **a, int m)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	t_stack *buff;

	buff = find_last(*a);
	buff->previous->next = NULL;
	buff->next = *a;
	buff->previous = NULL;
	(*a)->previous = buff;
	*a = buff;
	if (m == 1)
		ft_printf("rra\n");
}

void	rrb (t_stack **b, int m)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	t_stack *buff;

	buff = find_last(*b);
	buff->previous->next = NULL;
	buff->next = *b;
	buff->previous = NULL;
	(*b)->previous = buff;
	*b = buff;
	if (m == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
