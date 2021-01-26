/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sg9031 <sg9031@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 01:12:19 by sg9031            #+#    #+#             */
/*   Updated: 2021/01/26 17:52:08 by sg9031           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		load_from_memory(char **memory, char **line)
{
	int		len;
	char	*tmp;
	int		i;

	if (!*memory)
		return (1);
	if (!(tmp = ft_strdup(*memory)))
		return (0);
	free(*memory);
	*memory = NULL;
	len = line_length(tmp, 0);
	if (!(*line = malloc(sizeof(char) * (len + 2))))
		return (0);
	i = -1;
	while (++i < len)
		(*line)[i] = tmp[i];
	(*line)[i] = '\0';
	if (ft_strchr(tmp, '\n'))
		if (!(*memory = ft_strdup(ft_strchr(tmp, '\n') + 1)))
			return (0);
	i = (len != line_length(tmp, 1));
	free(tmp);
	return (1 + i);
}

int		create_tmp(char **line, char **tmp)
{
	if (*line)
	{
		*tmp = ft_strdup(*line);
		free(*line);
	}
	else
		*tmp = ft_strdup("\0");
	if (!*tmp)
		return (0);
	return (1);
}

int		complete_line(char **line, char *buffer)
{
	char	*tmp;
	int		i;
	int		current_line_length;
	int		buffer_line_length;

	if (!(create_tmp(line, &tmp)))
		return (0);
	current_line_length = line_length(tmp, 1);
	buffer_line_length = line_length(buffer, 0);
	if (!(*line = malloc(sizeof(char) * \
		(current_line_length + buffer_line_length + 1))))
		return (0);
	i = -1;
	while (++i < current_line_length)
		(*line)[i] = tmp[i];
	free(tmp);
	i = -1;
	while (++i < buffer_line_length)
		(*line)[current_line_length + i] = buffer[i];
	(*line)[current_line_length + i] = '\0';
	return (1);
}

int		read_from_fd(int fd, char **line, char **memory)
{
	ssize_t		r;
	char		buffer[BUFFER_SIZE + 1];

	r = 0;
	if (!*line || !ft_strchr(*line, '\n'))
	{
		while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[r] = '\0';
			if (!(complete_line(line, buffer)))
				return (0);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
		if (r < 0)
			return (0);
		if (r == 0)
			return (2);
		if (ft_strchr(buffer, '\n'))
			if (!(*memory = ft_strdup(ft_strchr(buffer, '\n') + 1)))
				return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*memory[256];
	int			code;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!(code = load_from_memory(&memory[fd], line)))
		return (-1);
	if (code == 2)
		return (1);
	if (!(code = read_from_fd(fd, line, &memory[fd])))
		return (-1);
	if (code == 2)
	{
		if (!*line)
			*line = ft_strdup("\0");
		return (0);
	}
	return (1);
}
