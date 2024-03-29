/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:20:00 by mbui              #+#    #+#             */
/*   Updated: 2019/06/26 13:55:01 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(const int fd, char **stack, char **line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i] != '\0')
		i++;
	if (stack[fd][i] == '\n')
	{
		MALLOK((*line = ft_strndup(stack[fd], i)));
		MALLOK((tmp = ft_strsub(stack[fd], i + 1, ft_strlen(stack[fd]))));
		free(stack[fd]);
		stack[fd] = tmp;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else if (stack[fd][i] == '\0')
	{
		MALLOK((*line = ft_strdup(stack[fd])));
		ft_strdel(&stack[fd]);
	}
	return (1);
}

static int	read_file(const int fd, char *buf, char **stack)
{
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!stack[fd])
		{
			MALLOK((stack[fd] = ft_strdup(buf)));
		}
		else if (stack[fd])
		{
			tmp = stack[fd];
			MALLOK((stack[fd] = ft_strjoin(tmp, buf)));
			ft_strdel(&tmp);
		}
		if (ft_strchr(stack[fd], '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*stack[OPEN_MAX];
	int			ret;

	if (!line || fd < 0 || fd > OPEN_MAX || read(fd, stack[fd], 0) < 0)
		return (-1);
	if ((ret = read_file(fd, buf, stack)) < 0)
		return (-1);
	else if (stack[fd])
		get_line(fd, stack, line);
	else if (ret == 0 && stack[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	return (1);
}
