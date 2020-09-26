/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 08:56:37 by agomes-a          #+#    #+#             */
/*   Updated: 2019/10/17 15:53:56 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_coord(t_tetro *tetro)
{
	int	x;
	int y;
	int j;
	int	d;

	y = -1;
	j = 0;
	d = 0;
	while (tetro->tab[++y])
	{
		x = -1;
		while (tetro->tab[y][++x])
			if (tetro->tab[y][x] == '#')
			{
				tetro->pos[j][0] = x;
				tetro->pos[j][1] = y;
				j++;
			}
			else if (tetro->tab[y][x] == '.')
				d++;
	}
	free_tab(tetro->tab, y);
	return ((j != 4 || d != 12) ? -1 : 0);
}

/*
** get_coord: get the coord of each block of a tetro on a tab
** return of get_coord(): check the right number of char for each tetro
*/

t_tetro	*lstdel_tetro(t_tetro **head)
{
	t_tetro	*curr;
	t_tetro	*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
	return (NULL);
}

t_tetro	*newt(char *file, int *j, char lettre)
{
	t_tetro	*new;
	int		i;

	i = 0;
	if (!(new = (t_tetro*)ft_memalloc(sizeof(t_tetro))))
		return (NULL);
	if (!(new->tab = (char**)ft_memalloc(sizeof(char*) * 5)))
		return (NULL);
	new->tab[4] = 0;
	new->let = lettre;
	new->next = 0;
	while (i < 4)
	{
		if (!(new->tab[i] = ft_strsub(file, *j, 4)))
			return ((t_tetro*)free_tab(new->tab, i));
		*j += 5;
		i++;
	}
	if (get_coord(new) == -1)
	{
		ft_strdel(&file);
		free(new);
		return (new = NULL);
	}
	return (new);
}

/*
** newt: initialize a node of the linked list
** stock: store each tetro in the linked list
** lstdel_tetro: deletes the linked list starting from the head
*/

t_tetro	*stock(char *file)
{
	t_tetro	*head;
	t_tetro	*new;
	int		j;
	char	let;

	j = 0;
	let = 'A';
	if (!(head = newt(file, &j, let)))
		return (NULL);
	let++;
	new = head;
	while (file[++j])
	{
		if (!(new->next = newt(file, &j, let)))
		{
			lstdel_tetro(&head);
			return (NULL);
		}
		new = new->next;
		let++;
	}
	head->nb = let - 'A';
	new->next = NULL;
	ft_strdel(&file);
	return (head);
}
