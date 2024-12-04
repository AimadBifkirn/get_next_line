/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:41:18 by abifkirn          #+#    #+#             */
/*   Updated: 2024/11/29 18:06:29 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(int fd)
{
	char	*l;
	ssize_t	br;

	l = malloc((size_t)BUFFER_SIZE + 1);
	if (!l)
		return (NULL);
	br = read(fd, l, BUFFER_SIZE);
	if (br <= 0)
	{
		free(l);
		return (NULL);
	}
	l[br] = '\0';
	return (l);
}

char	*get_line(char	*res)
{
	char		*result;
	size_t		i;

	i = 0;
	while (res[i] != '\0' && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		result = malloc(i + 2);
	else
		result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (res[i] != '\0' && res[i] != '\n')
	{
		result[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		result[i] = res[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*reset(char *reserv)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = 0;
	j = 0;
	while (reserv[i] != '\0' && reserv[i] != '\n')
		i++;
	new = malloc((ft_strlen(reserv) - i) + 1);
	if (!new)
		return (NULL);
	if (reserv[i] == '\n')
		i++;
	while (reserv[i] != '\0')
	{
		new[j] = reserv[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(reserv);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserv[1048576];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(reserv[fd], '\n'))
	{
		line = get_read(fd);
		if (!line)
			break ;
		reserv[fd] = ft_strjoin(reserv[fd], line);
	}
	if (!reserv[fd])
		return (NULL);
	result = get_line(reserv[fd]);
	reserv[fd] = reset(reserv[fd]);
	if (*reserv[fd] == '\0')
	{
		free(reserv[fd]);
		reserv[fd] = NULL;
	}
	return (result);
}
