/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:21:05 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:44:58 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*ft_strlen : calculates the length of the string pointed to by s, excluding
the terminating null byte ('\0').
Return value : the number of bytes in the string pointed to by s.*/

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*ft_strlcpy : copies up to size - 1 characters from the NUL-terminated string
src to dst, NUL-terminating the result. It take the full sizefull size of the
buffer (not just the length) and guarantee to NUL-terminate the result (as long
as size is larger than 0.
Return value : the total of src. */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
