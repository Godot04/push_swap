/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:52:51 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:14:38 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int m)
{
	if (!b || !*b)
		return ;
	t_stack *element_b = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	element_b->previous = NULL;
	element_b->next = *a;
	if (*a)
		(*a)->previous = element_b;
	*a = element_b;
	if (m == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int m)
{
	if (!b || !a || !*a)
		return ;
	t_stack *element_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	element_a->previous = NULL;
	element_a->next = *b;
	if (*b)
		(*b)->previous = element_a;
	*b = element_a;
	if (m == 1)
		ft_printf("pb\n");
}
