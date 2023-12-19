/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:59:42 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:46:59 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*rotate : shifts all elements of the stack one position upwards.
The first element becomes the last.*/

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	last_node->next = temp;
	temp->next = NULL;
	temp->previous = last_node;
	(*stack)->previous = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
