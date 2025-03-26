/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:04:00 by opopov            #+#    #+#             */
/*   Updated: 2025/03/25 20:51:03 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
	t_stack *current = *stack;
	t_stack *next;

	if (!stack)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	main_stack_operation(t_stack **stack, int buff)
{
	t_stack *new_node;
	t_stack *last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = buff;
	new_node->is_best_move_choice = 0;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

int	create_stack(char **argv, t_stack **stack)
{
	long buff;
	int	i;

	if (!ft_str_isdigit(argv))
		return (1);
	if (!ft_duplicate_check(argv))
		return (1);
	i = -1;
	while (argv[++i])
	{
		buff = ft_atol(argv[i]);
		if (buff > INT_MAX || buff < INT_MIN)
			return (1);
		main_stack_operation(stack, (int)buff);
	}
	return (0);
}

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	main (int argc, char **argv)
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int count;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"));
	if (argc == 2)
		argv = split(argv[1], ' ');
	if (create_stack(argv + 1, &a))
	{
		free_stack(&a);
		return (ft_printf("Error\n"));
	}
	count = count_stacks(a);
	if (stack_sorted(a) == 1)
	{
		if (count == 2)
			sa(&a, 1);
		else if (count == 3)
			sort_3(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
