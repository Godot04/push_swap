/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:03:02 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 13:15:07 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int m)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	t_stack *first = *a;
	t_stack *second = (*a)->next;

	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*a = second;
	if (m == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int m)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	t_stack *first = *b;
	t_stack *second = (*b)->next;

	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*b = second;
	if (m == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}
