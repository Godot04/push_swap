/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:04:11 by opopov            #+#    #+#             */
/*   Updated: 2025/03/26 18:56:31 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#define INT_MIN -2147483648L
#define INT_MAX 2147483647L

typedef struct s_stack
{
	int				value;
	int				index;
	int				rotations;
	int				is_below_medium;
	int				is_best_move_choice;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*previous;

}					t_stack;

t_stack	*find_last(t_stack *find);
t_stack	*find_highest(t_stack *find);
t_stack	*find_smallest(t_stack *find);
t_stack	*find_best_move_stack(t_stack *st);
void	pa(t_stack **a, t_stack **b, int m);
void	pb(t_stack **a, t_stack **b, int m);
void	sa(t_stack **a, int m);
void	sb(t_stack **b, int m);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a, int m);
void	rb(t_stack **b, int m);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int m);
void	rrb(t_stack **b, int m);
void	rrr(t_stack **a, t_stack **b);
int		count_stacks(t_stack *st);
void	index_counter (t_stack *st);
void	sort_3(t_stack **st);
void	sort_2(t_stack **st);
void	sort_4_and_5(t_stack **a, t_stack **b);
void	sort_stacks(t_stack **a, t_stack **b);
void	set_target_node_a(t_stack *a, t_stack *b);
void	small_to_top(t_stack **a);
void	operations_for_a(t_stack **a, t_stack **b, int st_len);
void	operations_for_b(t_stack **a, t_stack **b);
void	set_min_rotations(t_stack *st);
int		stack_sorted(t_stack *stack);
void	free_stack(t_stack **stack);

char	**split(char *s, char c);
