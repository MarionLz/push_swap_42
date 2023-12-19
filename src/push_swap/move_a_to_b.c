/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:36:54 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:49:56 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_closest_smaller_node(t_stack *a, t_stack *b)
{
	t_stack	*current_node_b;
	t_stack	*closest_node;

	while (a)
	{
		current_node_b = b;
		closest_node = NULL;
		while (current_node_b)
		{
			if (a->value > current_node_b->value && (closest_node == NULL
					|| closest_node->value < current_node_b->value))
				closest_node = current_node_b;
			current_node_b = current_node_b->next;
		}
		if (closest_node != NULL)
			a->target = closest_node;
		else
			a->target = find_max_node(b);
		a = a->next;
	}
}

void	count_moves(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = count_nodes(a);
	len_b = count_nodes(b);
	while (a)
	{
		if (a->above_median && a->target->above_median)
		{
			a->push_cost = a->index;
			if (a->index < a->target->index)
				a->push_cost = a->target->index;
		}
		if (!a->above_median && !a->target->above_median)
		{
			a->push_cost = len_a - a->index;
			if ((len_a - a->index) < (len_b - a->target->index))
				a->push_cost = len_b - a->target->index;
		}
		if (a->above_median && !a->target->above_median)
			a->push_cost = a->index + (len_b - a->target->index);
		if (!a->above_median && a->target->above_median)
			a->push_cost = (len_a - a->index) + a->target->index;
		a = a->next;
	}
}

t_stack	*find_cheapest_push(t_stack *a)
{
	t_stack	*cheapest_node;
	int		cost;

	cheapest_node = a;
	cost = a->push_cost;
	while (a)
	{
		if (a->push_cost < cost)
		{
			cost = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest_push = true;
	return (cheapest_node);
}

t_stack	*set_a_ready_to_push(t_stack *a, t_stack *b)
{
	t_stack	*cheapest_node;

	init_stack_index(a);
	init_stack_index(b);
	find_closest_smaller_node(a, b);
	count_moves(a, b);
	cheapest_node = find_cheapest_push(a);
	return (cheapest_node);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node_to_push;

	node_to_push = set_a_ready_to_push(*a, *b);
	if (node_to_push->above_median && node_to_push->target->above_median)
	{
		while (*a != node_to_push && *b != node_to_push->target)
			rr(a, b);
	}
	else if (!node_to_push->above_median && !node_to_push->target->above_median)
	{
		while (*a != node_to_push && *b != node_to_push->target)
			rrr(a, b);
	}
	init_stack_index(*a);
	init_stack_index(*b);
	do_last_moves(a, node_to_push, 'a');
	do_last_moves(b, node_to_push->target, 'b');
	pb(a, b);
}
