/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:58:06 by nadjemia          #+#    #+#             */
/*   Updated: 2024/07/24 12:24:13 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *buffer)
{
	size_t	size;

	size = 0;
	while (*buffer != '\n' && *buffer)
	{
		buffer++;
		size++;
	}
	if (*buffer == '\n')
		size++;
	return (size);
}

static void	ft_fill(char *buf, char *buffer, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_len(buffer);
	while (i < size)
		buffer[j++] = buf[i++];
}

char	*get_next_line(int fd)
{
	static char	buffer[1000000000];
	char		*buf;
	char		*str;
	int			i;
	int			len;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	ft_clean(buffer);
	len = ft_strlen(buffer);
	while (!(ft_isnl(buffer, len, &i)))
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		ft_bzero(buf, BUFFER_SIZE);
		if (ft_verif(read(fd, buf, BUFFER_SIZE), buf, buffer))
			return (NULL);
		ft_fill(buf, buffer, BUFFER_SIZE);
		free(buf);
		i += BUFFER_SIZE;
	}
	str = ft_str(buffer);
	return (str);
}

int	ft_isnl(char *buffer, int len, int *i)
{
	int	end;
	int	start;

	start = 0;
	end = *i + len;
	while (start < end)
	{
		if (buffer[start] == '\n' || buffer[start] == '\0')
			return (1);
		start++;
	}
	return (0);
}

char	*ft_str(char *buffer)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_len(buffer);
	str = (char *)malloc(sizeof(char) * (size + 1));
	ft_bzero(str, size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
