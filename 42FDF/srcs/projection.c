/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 07:38:00 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 13:17:05 by agomes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** turn_pos :
** turn all coordinates positive by adding the lowest coord to every coord
*/

void	turn_pos(t_pxl **start, double minx, double miny)
{
	t_pxl	*pxl;

	pxl = *start;
	while (pxl)
	{
		pxl->x -= minx - WIN_X / 4;
		pxl->y -= miny - WIN_Y / 4;
		pxl = pxl->nxt;
	}
}

void	calc_iso(t_pxl **start, t_cam cam)
{
	t_pxl	*pxl;
	double	minx;
	double	miny;

	minx = 0;
	miny = 0;
	pxl = *start;
	while (pxl)
	{
		pxl->x = (pxl->x - pxl->y) * cos(DEG_30);
		pxl->y = (pxl->x + pxl->y) * sin(DEG_30) - pxl->z;
		minx = (pxl->x < minx ? pxl->x : minx);
		miny = (pxl->y < miny ? pxl->y : miny);
		pxl = pxl->nxt;
	}
	turn_pos(start, minx, miny);
	if (cam.col_opt == 1)
		init_gradient(start);
}

void	calc_pers(t_pxl **start, t_cam cam)
{
	t_pxl	*pxl;
	double	minx;
	double	miny;

	minx = 0;
	miny = 0;
	pxl = *start;
	while (pxl)
	{
		pxl->x = (pxl->x + cam.x) * (cam.z / (cam.z + pxl->z));
		pxl->y = (pxl->y + cam.y) * (cam.z / (cam.z + pxl->z));
		minx = (pxl->x < minx ? pxl->x : minx);
		miny = (pxl->y < miny ? pxl->y : miny);
		pxl = pxl->nxt;
	}
	turn_pos(start, minx, miny);
	if (cam.col_opt == 1)
		init_gradient(start);
}

void	calc_ortho(t_pxl **start, t_cam cam)
{
	t_pxl	*pxl;
	double	minx;
	double	miny;

	minx = 0;
	miny = 0;
	pxl = *start;
	while (pxl)
	{
		pxl->x = pxl->x;
		pxl->y = pxl->y;
		pxl->z = 0;
		minx = (pxl->x < minx ? pxl->x : minx);
		miny = (pxl->y < miny ? pxl->y : miny);
		pxl = pxl->nxt;
	}
	turn_pos(start, minx, miny);
	if (cam.col_opt == 1)
		init_gradient(start);
}

void	projection(char *proj, t_pxl **fdf, t_cam cam)
{
	if (ft_strcmp(proj, "ISO") == 0)
		calc_iso(fdf, cam);
	else if (ft_strcmp(proj, "PER") == 0)
		calc_pers(fdf, cam);
	else if (ft_strcmp(proj, "ORT") == 0)
		calc_ortho(fdf, cam);
}
