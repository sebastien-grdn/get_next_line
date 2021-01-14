/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrondin <sgrondin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:15:27 by sgrondin          #+#    #+#             */
/*   Updated: 2021/01/14 16:39:55 by sgrondin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    ssize_t x;
    char buffer[BUFFER_SIZE];
    size_t size = BUFFER_SIZE;
    char *total;

    x = 1;
    while ((x = read(fd, buffer, BUFFER_SIZE - 1)) > 0)
    {
        buffer[x] = '\0';
        if (total)
            total = ft_strjoin(total, buffer);
        else
            total = ft_strdup(buffer);
        if (x < BUFFER_SIZE)
            break;
    }
    *line = total;
    return (1);
}

int main(void)
{
    int x = 1;
    char *line;

    x = get_next_line(1, &line);

    printf("yolo: %s\n", line);
}