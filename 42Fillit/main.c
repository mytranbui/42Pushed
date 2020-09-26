/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:32:04 by mbui              #+#    #+#             */
/*   Updated: 2019/10/18 09:36:52 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_and_free(t_tetro **head, char **map)
{
	int i;

	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
	free_tab(map, i);
	lstdel_tetro(head);
}

int		get_solv(t_tetro *tetro)
{
	char	**map;
	double	size;
	int		p[2];
	t_tetro	**head;

	p[0] = -1;
	p[1] = -1;
	head = &tetro;
	size = ft_sqrt(tetro->nb * 4);
	if (size - (int)size != 0)
		size++;
	if (!(map = init_map(size)))
		return (-1);
	while (!(map = solver(tetro, size, map, p)))
	{
		p[0] = -1;
		p[1] = -1;
		size++;
		if (!(map = init_map(size)))
			return (-1);
	}
	print_and_free(head, map);
	return (1);
}

int		main(int argc, char **argv)
{
	t_tetro	*tetro;
	char	*file;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [file]");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if ((file = ft_read(fd)) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if ((tetro = stock(file)) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if ((get_solv(tetro)) == -1)
		return (-1);
	return (0);
}
