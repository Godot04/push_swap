/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:01:29 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:14:58 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int m)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	t_stack *buff_last;
	t_stack *buff;

	buff = *a;
	buff_last = find_last(*a);
	*a = buff->next;
	(*a)->previous = NULL;
	buff_last->next = buff;
	buff->previous = buff_last;
	buff->next = NULL;
	if (m == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int m)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	t_stack *buff_last;
	t_stack *buff;

	buff = *b;
	buff_last = find_last(*b);
	*b = buff->next;
	(*b)->previous = NULL;
	buff_last->next = buff;
	buff->previous = buff_last;
	buff->next = NULL;
	if (m == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
