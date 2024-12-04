/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:00:25 by abifkirn          #+#    #+#             */
/*   Updated: 2024/11/28 14:03:22 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			size1;
	size_t			size2;
	char			*res;

	if (s1 == NULL)
		return (s2);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *)malloc(size1 + size2 + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, size1);
	ft_memcpy(res + size1, s2, size2);
	res[size1 + size2] = '\0';
	free(s1);
	free(s2);
	return (res);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}
