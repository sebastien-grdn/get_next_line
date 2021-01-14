/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrondin <sgrondin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:15:27 by sgrondin          #+#    #+#             */
/*   Updated: 2021/01/14 17:38:58 by sgrondin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*new_string;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_string = malloc(total_size + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		new_string[i++] = *s1++;
	while (*s2)
		new_string[i++] = *s2++;
	new_string[i] = '\0';
	return (new_string);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
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
	size_t srcsize;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
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