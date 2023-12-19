/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:59:32 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 18:03:49 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (!*stack_src)
		return ;
	temp = (*stack_src);
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->previous = NULL;
	if (!*stack_dest)
	{
		*stack_dest = temp;
		(*stack_dest)->next = NULL;
	}
	else
	{
		temp->next = *stack_dest;
		temp->next->previous = temp;
		*stack_dest = temp;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
