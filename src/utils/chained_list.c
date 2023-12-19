/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:41:04 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:43:04 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*find_last_node : returns the last node of the stack.*/

t_stack	*find_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

/*count_nodes : count the number of nodes in the stack.*/

int	count_nodes(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/*find_max_node : find the node with the maximum value in the stack.*/

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->value < stack->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

/*find_min_node : find the node with the minimum value in the stack.*/

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->value > stack->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
