/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:03:02 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 21:05:11 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void command_swap(t_stack **st)
{
	if (*st == NULL || (*st)->next == NULL)
		return ;
	t_stack *first = *st;
	t_stack *second = (*st)->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*st = second;
}

void	sa(t_stack **a, int m)
{
	command_swap(a);
	if (m == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int m)
{
	command_swap(b);
	if (m == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int m)
{
	command_swap(a);
	command_swap(b);
	if (m == 1)
		ft_printf("ss\n");
}
