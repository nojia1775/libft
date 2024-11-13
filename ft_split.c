/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojia <nojia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:31:20 by nojia             #+#    #+#             */
/*   Updated: 2024/11/13 15:28:03 by nojia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	get_strings(char **result, char *str, size_t size)
{
	size_t	i;
	size_t	word;
	size_t	tmp;
	
	word = 0;
	i = 0;
	tmp = 0;
	while (i < size)
	{
		if (!str[i] || (i != 0 && str[i - 1] != '\0'))
			;
		else
		{
			result[word] = ft_strdup(str + i);
			if (!result[word++])
			{
				while (tmp < word)
					free(result[tmp++]);
				return (free(result));
			}
		}
		i++;
	}
}

static size_t	count_words(char *str, size_t size)
{
	size_t	i;
	size_t	count;
	
	count = 0;
	i = 0;
	while (i < size)
	{
		if (i == 0 && str[i])
			count++;
		else if (str[i] && str[i - 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *str, char *set)
{
	size_t	i;
	size_t	count_word;
	char	**result;
	size_t	size;
	char	*tmp;

	tmp = ft_strdup(str);
	if (!tmp)
		return (NULL);
	size = ft_strlen(tmp);
	i = 0;
	while (i < size)
	{
		if (ft_strchr(set, tmp[i]))
			tmp[i] = '\0';
		i++;
	}
	count_word = count_words(tmp, size);
	result = (char **)ft_calloc(count_word + 1, sizeof(char *));
	if (!result)
		return (NULL);
	get_strings(result, tmp, size);
	free(tmp);
	return (result);
}