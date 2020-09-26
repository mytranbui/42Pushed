/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:20:57 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/13 13:36:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_image(t_pxl **start, int width, int *data)
{
	t_pxl	*pxl;
	t_pxl	*nxt;

	pxl = *start;
	while (pxl->nxt)
	{
		if (pxl->line == pxl->nxt->line)
			draw_line(*pxl, *(pxl->nxt), width, data);
		pxl = pxl->nxt;
	}
	pxl = *start;
	nxt = *start;
	while (nxt->nxt && pxl->line == nxt->line)
		nxt = nxt->nxt;
	while (nxt)
	{
		draw_line(*pxl, *nxt, width, data);
		pxl = pxl->nxt;
		nxt = nxt->nxt;
	}
}

void	init_pxl(t_pxl *pxl0, t_pxl *pxl1, int steep)
{
	if (steep == 1)
	{
		ft_swap_db(&pxl0->x, &pxl0->y);
		ft_swap_db(&pxl1->x, &pxl1->y);
	}
	if (pxl0->x > pxl1->x)
	{
		ft_swap_db(&pxl0->x, &pxl1->x);
		ft_swap_db(&pxl0->y, &pxl1->y);
	}
}

void	draw_line(t_pxl pxl0, t_pxl pxl1, int width, int *data)
{
	int	steep;

	steep = ft_abs(pxl1.y - pxl0.y) > ft_abs(pxl1.x - pxl0.x) ? 1 : 0;
	init_pxl(&pxl0, &pxl1, steep);
	if (steep == 1)
		steep_line(pxl0, pxl1, width, data);
	else
		nosteep_line(pxl0, pxl1, width, data);
}
