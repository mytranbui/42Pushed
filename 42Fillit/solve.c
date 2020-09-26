/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:12:04 by agomes-a          #+#    #+#             */
/*   Updated: 2019/10/15 11:26:40 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**init_map(int size)
{
	char	**map;
	int		i;
	int		j;

	j = -1;
	if (!(map = (char**)ft_memalloc(sizeof(char*) * (size_t)size + 1)))
		return (NULL);
	while (++j < size)
	{
		if (!(map[j] = (char*)ft_strnew(sizeof(char) * (size_t)size + 1)))
			return (NULL);
		i = 0;
		while (i < size)
			map[j][i++] = '.';
	}
	map[j] = 0;
	return (map);
}

int		find_space(char **map, int pos[4][2], int p[2], int size)
{
	int	l;
	int x;
	int y;

	while (map[++p[1]])
	{
		while (map[p[1]][++p[0]])
		{
			l = 1;
			while (l < 4 && map[p[1]][p[0]] == '.')
			{
				x = p[0] + pos[l][0] - pos[0][0];
				y = p[1] + pos[l][1] - pos[0][1];
				l = (y > size - 1 || x < 0 || map[y][x] != '.') ? 5 : l + 1;
				if (l == 4)
					return (1);
			}
		}
		p[0] = -1;
	}
	return (-1);
}

int		check_map(char **map, int *i, int *j, int size)
{
	*j = -1;
	while (map[++(*j)])
	{
		*i = -1;
		while (map[*j][++(*i)])
			if (map[*j][*i] != '.')
			{
				free_tab(map, size);
				return (-1);
			}
	}
	free_tab(map, *j);
	return (1);
}

void	add_tetro(t_tetro *tetro, char **map, int i, int j)
{
	int	k;

	k = -1;
	map[j][i] = tetro->let;
	while (++k < 3)
	{
		i -= (tetro->pos[k][0] - tetro->pos[k + 1][0]);
		j -= (tetro->pos[k][1] - tetro->pos[k + 1][1]);
		map[j][i] = tetro->let;
	}
}

/*
** solver: use of backtracking to get the solution
** add_tetro: add the tetro on the map where the find_space indicates
** check_map: check if there are only dots on the map
*/

char	**solver(t_tetro *tetro, int size, char **map, int p[2])
{
	char	**tmp;
	int		t[2];

	tmp = NULL;
	if ((find_space(map, tetro->pos, p, size)) == 1)
	{
		if (!(tmp = tabcpy(map, (size_t)size)))
			return (NULL);
		t[0] = p[0];
		t[1] = p[1];
		add_tetro(tetro, map, p[0], p[1]);
		p[0] = -1;
		p[1] = -1;
		if (tetro->next != 0 && (map = solver(tetro->next, size, map, p)) == 0)
		{
			if (!(map = tabcpy(tmp, (size_t)size)))
				return (NULL);
			t[1]--;
			map = solver(tetro, size, map, t);
		}
	}
	else if (check_map(map, &p[0], &p[1], size))
		return (NULL);
	free_tab(tmp, size);
	return (map);
}
