/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nojia <nojia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:51:58 by nadjemia          #+#    #+#             */
/*   Updated: 2024/11/13 14:02:26 by nojia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	
	if (s1 == NULL || set == NULL)
		return (NULL);
	str = ft_strdup(s1);
	if (!str)
		return (NULL);
	i = ft_strlen(s1);
	while (--i >= 0)
	{
		if (!ft_strchr(set, s1[i]))
		{
			str[i + 1] = '\0';
			break ;
		}
	}
	while (ft_strchr(set, str[0]))
	{
		i = -1;
		while (str[++i])
			str[i] = str[i + 1];
	}
	return (str);
}
