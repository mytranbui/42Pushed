/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:11:34 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 14:23:40 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		lstdel_fdf(t_pxl **head)
{
	t_pxl	*curr;
	t_pxl	*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->nxt;
		free(curr);
		curr = next;
	}
	*head = NULL;
	return (-1);
}

int		storing(t_pxl **pxl, char **vals, int y, int col_opt)
{
	int		i;
	t_pxl	*tmp;

	tmp = *pxl;
	i = -1;
	while (vals[++i] != 0)
	{
		if (i > 0)
			if (!(tmp->nxt = (t_pxl*)malloc(sizeof(t_pxl))))
				return (lstdel_fdf(pxl));
		tmp = i > 0 ? tmp->nxt : tmp;
		tmp->x = (double)(i + 1) * pxl[0]->zoom;
		tmp->y = (double)(y + 1) * pxl[0]->zoom;
		tmp->z = ((double)ft_atoi(vals[i]) + 1) * pxl[0]->zoom;
		tmp->line = y;
		if (col_opt == 0)
			tmp->color = get_rgb(vals[i]);
	}
	*pxl = tmp;
	free_tab(vals, i - 1);
	return (1);
}

/*
** coord + 1 : to avoid negative values at 0
*/

int		read_store(int fd, t_pxl **start, int col_opt)
{
	char	*line;
	int		ret;
	int		i;
	char	**vals;
	t_pxl	*pxl;

	pxl = *start;
	i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (i > 0)
			if (!(pxl->nxt = (t_pxl*)malloc(sizeof(t_pxl))))
				return (lstdel_fdf(start));
		pxl = i > 0 ? pxl->nxt : pxl;
		pxl->zoom = start[0]->zoom;
		vals = ft_strsplit(line, ' ');
		storing(&pxl, vals, i, col_opt);
		free(line);
		i++;
	}
	pxl->nxt = 0;
	close(fd);
	return (ret);
}

void	copy_next(t_pxl *copy, t_pxl *tmp)
{
	copy->x = tmp->x;
	copy->y = tmp->y;
	copy->z = tmp->z;
	copy->line = tmp->line;
	copy->zoom = tmp->zoom;
	copy->color = tmp->color;
}

t_pxl	*copy_fdf(t_pxl **fdf, t_pxl **start)
{
	t_pxl	*copy;
	t_pxl	*tmp;

	copy = *start;
	tmp = *fdf;
	copy_next(copy, tmp);
	tmp = tmp->nxt;
	while (tmp != 0)
	{
		if (!(copy->nxt = (t_pxl*)malloc(sizeof(t_pxl))))
			return (NULL);
		copy = copy->nxt;
		copy_next(copy, tmp);
		tmp = tmp->nxt;
	}
	copy->nxt = 0;
	return (*start);
}
