/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:48:01 by mbui              #+#    #+#             */
/*   Updated: 2020/01/17 09:34:16 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	reading(int fd, char buf[], char **p, char **line)
{
	int	ret;

	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = 0;
	p[0] = buf;
	return (ret);
}

static int	save_line(char **line, int len, char *buf)
{
	char	*t1;
	char	*t2;

	if (line[0] == 0)
	{
		if (!(line[0] = ft_strnew(len)))
			return (-1);
		ft_strncpy(line[0], buf, len);
	}
	else
	{
		if (!(t1 = ft_strnew(len - ft_strlen(line[0]))) ||
				!(t2 = ft_strnew(ft_strlen(line[0]))))
			return (-1);
		ft_strcpy(t2, line[0]);
		ft_strncpy(t1, buf, len - ft_strlen(line[0]));
		ft_strdel(line);
		if ((line[0] = ft_strjoin(t2, t1)) == NULL)
			return (-1);
		ft_strdel(&t1);
		ft_strdel(&t2);
	}
	return (0);
}

static int	empty_line(int ret, char **line)
{
	if (ret == 0 && ft_strlen(line[0]) == 0)
	{
		ft_strdel(line);
		line[0] = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static int	ret;
	static char	buf[BUFF_SIZE + 1];
	static char	*p;
	int			len;

	if (!line || fd < 0 || fd > OPEN_MAX || !p || !(*p))
		if ((ret = reading(fd, buf, &p, line)) == -1)
			return (-1);
	line[0] = 0;
	len = 0;
	while (*p != '\n' && *p != 0 && p++)
		len++;
	if (save_line(line, len, len == BUFF_SIZE ? buf : p - len) == -1)
		return (-1);
	while (*p == buf[BUFF_SIZE] && *p != '\n' && ret > 0 && len != 0)
	{
		if ((ret = reading(fd, buf, &p, line)) == -1)
			return (-1);
		while (*p != '\n' && *p != 0 && p++)
			len++;
		if (save_line(line, len, buf) == -1)
			return (-1);
	}
	*p != 0 ? p++ : p;
	return (empty_line(ret, line));
}
