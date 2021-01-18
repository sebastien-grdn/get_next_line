/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sg9031 <sg9031@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:54:52 by sg9031            #+#    #+#             */
/*   Updated: 2021/01/18 15:39:15 by sg9031           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_length(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i + 1);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	if (!dst || !src)
		return (0);
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize > srcsize + 1)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*x;
	char	*y;

	if (!dst && !src)
		return (dst);
	x = (char *)src;
	y = (char *)dst;
	i = -1;
	while (++i < n)
	{
		y[i] = x[i];
	}
	return (dst);
}
