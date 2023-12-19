/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:50:49 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:16:47 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc <= 1)
		return (1);
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
	}
	init_stack(argv, &a, i);
	sort_stack(&a, &b);
	free_stack(&a);
}
