/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:08:04 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:48:10 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three_nodes(t_stack **a)
{
	t_stack	*max_node;

	max_node = find_max_node(*a);
	if ((*a)->value == max_node->value)
		ra(a);
	else if ((*a)->next->value == max_node->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	init_stack_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = count_nodes(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	do_last_moves(t_stack **stack, t_stack *head_node, char id)
{
	while (*stack != head_node)
	{
		if (id == 'a')
		{
			if (head_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		if (id == 'b')
		{
			if (head_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		len_a;
	int		i;
	t_stack	*min_node;

	len_a = count_nodes(*a);
	i = 0;
	if (len_a == 2 && !stack_is_sorted(*a))
		sa(a);
	else if (len_a == 3 && !stack_is_sorted(*a))
		sort_three_nodes(a);
	else if (len_a > 3 && !stack_is_sorted(*a))
	{
		while (i++ < 2)
			pb(a, b);
		len_a -= 2;
		while (len_a-- > 3)
			move_a_to_b(a, b);
		sort_three_nodes(a);
		while (*b)
			move_b_to_a(a, b);
		min_node = find_min_node(*a);
		if ((*a)->value != min_node->value)
			do_last_moves(a, min_node, 'a');
	}
}
