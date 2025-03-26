/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:52:51 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 21:05:32 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void command_push(t_stack **dst, t_stack **src)
{
	if (!*src)
		return ;
	t_stack *push_element = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	push_element->previous = NULL;
	push_element->next = *dst;
	if (*dst)
		(*dst)->previous = push_element;
	*dst = push_element;
}

void	pa(t_stack **a, t_stack **b, int m)
{
	command_push(a, b);
	if (m == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int m)
{
	command_push(b, a);
	if (m == 1)
		ft_printf("pb\n");
}
