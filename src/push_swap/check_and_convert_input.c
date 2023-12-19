/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_convert_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:54:22 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:21:43 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*is_digit : check that the input is only digits.
It is possible to have a single "+" or "-" sign before the number.*/

bool	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

/*is_not_double : check that there are no duplicates in the number serie.*/

bool	is_not_double(char **argv, char *str, int j)
{
	unsigned int	i;

	while (argv[j])
	{
		i = 0;
		while (str[i] && argv[j][i] && str[i] == argv[j][i])
			i++;
		if (i == ft_strlen(str) && i == ft_strlen(argv[j]))
			return (false);
		j++;
	}
	return (true);
}

/*char_to_int : converts the string pointed to by str to int.*/

int	str_to_int(char *str)
{
	int			sign;
	long int	digit;

	sign = 1;
	digit = 0;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		digit = (digit * 10) + *str - 48;
		str++;
	}
	return (digit * sign);
}
