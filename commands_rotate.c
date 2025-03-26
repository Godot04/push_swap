/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:01:29 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 21:05:17 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_rotate(t_stack **st)
{
	if (*st == NULL || (*st)->next == NULL)
		return ;
	t_stack *buff;
	t_stack *buff_last;

	buff = *st;
	buff_last = find_last(*st);
	*st = buff->next;
	(*st)->previous = NULL;
	buff_last->next = buff;
	buff->previous = buff_last;
	buff->next = NULL;
}

void	ra(t_stack **a, int m)
{
	command_rotate(a);
	if (m == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int m)
{
	command_rotate(b);
	if (m == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int m)
{
	command_rotate(a);
	command_rotate(b);
	if (m == 1)
		ft_printf("rr\n");
}
