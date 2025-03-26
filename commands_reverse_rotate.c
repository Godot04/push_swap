/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:02:13 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 21:05:27 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_reverse_rotate(t_stack **st)
{
	t_stack *rotate_element;
	if (*st == NULL || (*st)->next == NULL)
		return ;
	rotate_element = find_last(*st);
	if (!rotate_element || !rotate_element->previous)
		return ;
	rotate_element->previous->next = NULL;
	rotate_element->next = *st;
	rotate_element->previous = NULL;
	(*st)->previous = rotate_element;
	*st = rotate_element;
}

void	rra (t_stack **a, int m)
{
	command_reverse_rotate(a);
	if (m == 1)
		ft_printf("rra\n");
}

void	rrb (t_stack **b, int m)
{
	command_reverse_rotate(b);
	if (m == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int m)
{
	command_reverse_rotate(a);
	command_reverse_rotate(b);
	if (m == 1)
		ft_printf("rrr\n");
}
