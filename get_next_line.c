/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:11:18 by abifkirn          #+#    #+#             */
/*   Updated: 2024/12/01 20:06:33 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*reserv;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(reserv, '\n'))
	{
		line = get_read(fd);
		if (!line)
			break ;
		reserv = ft_strjoin(reserv, line);
	}
	if (!reserv)
		return (NULL);
	result = get_line(reserv);
	reserv = reset(reserv);
	if (*reserv == '\0')
	{
		free(reserv);
		reserv = NULL;
	}
	return (result);
}
