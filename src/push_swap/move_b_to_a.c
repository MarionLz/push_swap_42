/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:39:20 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:50:26 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_closest_bigger_node(t_stack *a, t_stack *b)
{
	t_stack	*current_node_a;
	t_stack	*closest_node;

	while (b)
	{
		current_node_a = a;
		closest_node = NULL;
		while (current_node_a)
		{
			if (b->value < current_node_a->value && (closest_node == NULL
					|| closest_node->value > current_node_a->value))
				closest_node = current_node_a;
			current_node_a = current_node_a->next;
		}
		if (closest_node != NULL)
			b->target = closest_node;
		else
			b->target = find_min_node(a);
		b = b->next;
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	init_stack_index(*a);
	init_stack_index(*b);
	find_closest_bigger_node(*a, *b);
	do_last_moves(a, (*b)->target, 'a');
	pa(b, a);
}
