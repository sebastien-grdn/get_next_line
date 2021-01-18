/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sg9031 <sg9031@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:15:27 by sgrondin          #+#    #+#             */
/*   Updated: 2021/01/18 13:14:15 by sg9031           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*save_rem(char *total)
{
	int i;
	int start;

	i = 0;
	while (total[i] && total[i] != '\n')
		i++;
	start = i;
	while (total[i])
		i++;
	if (i != start)
		return (ft_strdup(&total[start + 1]));
	return (NULL);
}

int		line_length(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i + 1);
}

int		read_file(int fd, char *total[], char *buffer)
{
	ssize_t		r;

	r = 0;
	if (!*total || !ft_strchr(*total, '\n'))
	{
		r = 1;
		while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[r] = '\0';
			if (*total)
				*total = ft_strjoin(*total, buffer);
			else
				*total = ft_strdup(buffer);
			if (r < BUFFER_SIZE || ft_strchr(*total, '\n'))
				break ;
		}
	}
	if (r < 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*total;
	static char *rem[256];

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (rem[fd])
	{
		total = ft_strdup(rem[fd]);
		free(rem[fd]);
		rem[fd] = NULL;
	}
	if (read_file(fd, &total, buffer) < 0)
		return (-1);
	if (!total || ft_strlen(total) == 0)
	{
		*line = ft_strdup("\0");
		return (0);
	}
	if (line_length(total) < (int)ft_strlen(total))
		rem[fd] = save_rem(total);
	*line = malloc(sizeof(char) * line_length(total));
	ft_strlcpy(*line, total, line_length(total));
	free(total);
	return (1);
}
