/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:59:56 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:47:32 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*swap = swaps the first 2 elements at the top of the stack.*/

void	swap(t_stack **stack)
{
	int	temp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
