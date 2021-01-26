/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sg9031 <sg9031@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 01:09:36 by sg9031            #+#    #+#             */
/*   Updated: 2021/01/26 17:25:42 by sg9031           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (char*)&s[i];
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (char*)&s[i];
	return (0);
}

int		line_length(char *line, int entire)
{
	int i;

	i = 0;
	if (entire)
		while (line[i])
			i++;
	else
		while (line[i] && line[i] != '\n')
			i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (src[len])
		len += 1;
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
