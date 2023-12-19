/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:20:28 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:44:09 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*ft_split : allocates (malloc) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end with a
NULL pointer.
Return value :
- the array of new strings resulting from the split.
- NULL if the allocation fails.*/

int	ft_count_bloc(char const *s, char c)
{
	int		i;
	int		count_bloc;

	i = 0;
	count_bloc = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			count_bloc++;
		i++;
	}
	return (count_bloc);
}

char	*malloc_str(char **tab, int j, int count_char)
{
	tab[j] = (char *)malloc(count_char * sizeof(char) + 1);
	if (!tab[j])
	{
		while (j > 0)
		{
			j--;
			free (tab[j]);
		}
		free (tab);
		return (NULL);
	}
	return (tab[j]);
}

char	**ft_count_char(char const *s, char c, char **tab, int size)
{
	int	i;
	int	j;
	int	count_char;

	i = 0;
	j = 0;
	while (s[i] && j < size)
	{
		count_char = 0;
		while (s[i] != c && s[i])
		{
			count_char++;
			i++;
		}
		if ((s[i] == c || s[i] == '\0') && i != 0 && s[i - 1] != c)
		{
			tab[j] = malloc_str(tab, j, count_char);
			if (!tab[j])
				return (NULL);
			ft_strlcpy(tab[j], &s[i - count_char], count_char + 1);
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		size_tab;
	char	**tab;

	size_tab = ft_count_bloc(s, c);
	if (size_tab <= 1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	tab = (char **)malloc((size_tab + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (ft_count_char(s, c, tab, size_tab) == NULL)
		return (NULL);
	tab[size_tab] = NULL;
	return (tab);
}
