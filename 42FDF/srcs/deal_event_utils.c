/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_event_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:58:04 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/14 12:12:09 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotationx(t_pxl **start, double angle)
{
	t_pxl *tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->x = tmp->x;
		tmp->y = tmp->y * cos(angle) + tmp->z * (-sin(angle));
		tmp->z = tmp->y * sin(angle) + tmp->z * cos(angle);
		tmp = tmp->nxt;
	}
}

void	rotationy(t_pxl **start, double angle)
{
	t_pxl *tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->x = tmp->x * cos(angle) + tmp->z * sin(angle);
		tmp->y = tmp->y;
		tmp->z = tmp->x * (-sin(angle)) + tmp->z * cos(angle);
		tmp = tmp->nxt;
	}
}

void	rotationz(t_pxl **start, double angle)
{
	t_pxl *tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->x = tmp->x * cos(angle) + tmp->y * (-sin(angle));
		tmp->y = tmp->x * sin(angle) + tmp->y * cos(angle);
		tmp->z = tmp->z;
		tmp = tmp->nxt;
	}
}

void	zoom(t_pxl **start, double mult)
{
	t_pxl *tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->x *= mult;
		tmp->y *= mult;
		tmp = tmp->nxt;
	}
}

void	move(t_pxl **start, int x, int y)
{
	t_pxl *tmp;

	tmp = *start;
	while (tmp)
	{
		tmp->x += x;
		tmp->y += y;
		tmp = tmp->nxt;
	}
}
