/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:57:50 by mbui              #+#    #+#             */
/*   Updated: 2019/10/15 12:04:08 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(int fd)
{
	char	*file;
	int		ret;
	int		i;

	if (!(file = ft_strnew(MAX_READ + 1)))
		return (NULL);
	if ((ret = read(fd, file, MAX_READ + 1)) <= 0 || ret > MAX_READ)
	{
		ft_strdel(&file);
		return (NULL);
	}
	i = -1;
	while (file[++i])
		if (file[i] != '#' && file[i] != '\n' && file[i] != '.')
		{
			ft_strdel(&file);
			return (NULL);
		}
	if (link_count(file) == 1)
	{
		ft_strdel(&file);
		return (NULL);
	}
	return (file);
}

/*
** ft_read: read and store in file and check if there are only valid characters
** link_count: count the number of links between each block of a tetro
** check_link: check the valid number of links for each tetro
*/

int		check_link(int *n, int *i)
{
	if (!(*n == 6 || *n == 8))
		return (-1);
	*n = 0;
	*i += 2;
	return (1);
}

int		link_count(char *file)
{
	int	i;
	int	n;
	int	x;

	i = -1;
	n = 0;
	x = 0;
	while (file[++i])
	{
		x++;
		if (file[i] == '\n' && file[i + 1] == '\n')
			if ((x = check_link(&n, &i)) == -1)
				return (1);
		if (file[i] == '#')
		{
			file[i - 1] == '#' ? n++ : n;
			file[i + 1] == '#' ? n++ : n;
			(file[i - 5] == '#' && x - 5 > 0) ? n++ : n;
			(file[i + 5] == '#' && x + 5 < 20) ? n++ : n;
		}
	}
	if (check_link(&n, &i) == -1)
		return (1);
	return (0);
}
