/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:48 by nadjemia          #+#    #+#             */
/*   Updated: 2024/07/24 12:24:34 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*buffer == '\0')
		return ;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (buffer[j])
		buffer[j++] = '\0';
}

int	ft_verif(int r, char *buf, char *buffer)
{
	int	i;

	i = 0;
	if (r <= 0 && buffer[0] == '\0')
	{
		free(buf);
		while (buffer[i])
			buffer[i++] = '\0';
		return (1);
	}
	return (0);
}
