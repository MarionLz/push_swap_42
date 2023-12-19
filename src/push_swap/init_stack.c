/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:49:45 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:26:27 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*create_new_node : create a new node in the stack a and place it a the end of
the stack.*/

void	add_new_node(int value, t_stack **a)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	new_node->target = NULL;
	if (!(*a))
		*a = new_node;
	else
	{
		last_node = find_last_node(*a);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

/*init_stack : check that the input is valid. If yes, the input is converted
into an int and the stack is initialised by adding a new node.
If the input is invalid, the program display an error.*/

void	init_stack(char **argv, t_stack **a, int i)
{
	int		j;
	long	value;
	int		is_split;

	is_split = 0;
	if (i == 0)
		is_split = 1;
	while (argv[i])
	{
		j = i + 1;
		if (ft_strlen(argv[i]) == 0 || !is_digit(argv[i])
			|| !is_not_double(argv, argv[i], j))
			free_and_print_error(argv, a, is_split);
		value = str_to_int(argv[i]);
		if (value < -2147483648 || value > 2147483647)
			free_and_print_error(argv, a, is_split);
		add_new_node(value, a);
		i++;
	}
}
