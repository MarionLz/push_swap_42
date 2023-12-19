/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:51:37 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:29:43 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*free_stack : free the stack entirely.*/

void	free_stack(t_stack **stack)
{
	t_stack	*temp_node;
	t_stack	*current_node;

	current_node = *stack;
	if (!*stack)
		return ;
	while (current_node)
	{
		temp_node = current_node->next;
		free(current_node);
		current_node = temp_node;
	}
	*stack = NULL;
}

/*free_and_print_error : free the memory allocated, display an error and quit
the program.*/

void	free_and_print_error(char **argv, t_stack **a, int is_split)
{
	int	i;

	i = 0;
	if (is_split == 1)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free_stack(a);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
