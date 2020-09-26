/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:22:44 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 14:02:31 by agomes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	add_to_img(int pos[2], double y, int *data, t_pxl pxl0)
{
	data[pos[0]] = rgb_to_int(pxl0.color, 1 - (y - floor(y)));
	data[pos[1]] = rgb_to_int(pxl0.color, y - floor(y));
}

void	win_steep(double x[2], double y[2], double grad)
{
	double	b0;
	double	a0;

	if (x[0] > LIM_Y || y[0] > LIM_X)
		x[1] = x[0];
	else
	{
		while (x[1] > LIM_Y)
		{
			if (x[0] > x[1] - 1)
				break ;
			x[1]--;
		}
		b0 = y[0];
		a0 = x[0];
		while (b0 < LIM_X && ++a0 <= x[1] - 1)
			b0 += grad;
		if (b0 >= LIM_X)
			x[1] = a0;
	}
}

void	steep_line(t_pxl pxl0, t_pxl pxl1, int width, int *data)
{
	double	x[2];
	double	grad;
	double	y[2];
	int		pos[2];

	grad = (pxl1.x - pxl0.x) == 0. ? 1. : (pxl1.y - pxl0.y) / (pxl1.x - pxl0.x);
	x[0] = round(pxl0.x);
	y[0] = pxl0.y + grad * (x[0] - pxl0.x);
	if (floor(y[0]) <= LIM_X && x[0] <= LIM_Y &&
		y[0] >= 0 && x[0] >= 0)
		data[(int)(x[0] * width + floor(y[0]))] = rgb_to_int(pxl0.color, 1);
	y[0] += grad;
	x[1] = round(pxl1.x);
	y[1] = pxl1.y + grad * (x[1] - pxl1.x);
	if (floor(y[1]) <= LIM_X && x[1] <= LIM_Y &&
		y[1] >= 0 && x[1] >= 0)
		data[(int)(x[1] * width + floor(y[1]))] = rgb_to_int(pxl1.color, 1);
	win_steep(x, y, grad);
	while (++x[0] <= x[1] - 1)
	{
		pos[0] = x[0] * width + (int)floor(y[0]);
		pos[1] = pos[0] + 1;
		(floor(y[0]) >= 0 && x[0] >= 0) ? add_to_img(pos, y[0], data, pxl0) : 0;
		y[0] += grad;
	}
}

void	win_nosteep(double x[2], double y[2], double grad)
{
	double	a0;
	double	b0;

	if (x[0] > LIM_X || y[0] > LIM_Y)
		x[1] = x[0];
	else
	{
		while (x[1] > LIM_X)
		{
			if (x[0] > x[1] - 1)
				break ;
			x[1]--;
		}
		a0 = x[0];
		b0 = y[0];
		while (b0 < LIM_Y && ++a0 <= x[1] - 1)
			b0 += grad;
		if (b0 >= LIM_Y)
			x[1] = a0;
		x[1] = a0;
	}
}

void	nosteep_line(t_pxl pxl0, t_pxl pxl1, int width, int *data)
{
	double	x[2];
	double	grad;
	double	y[2];
	int		pos[2];

	grad = (pxl1.x - pxl0.x) == 0 ? 1 : (pxl1.y - pxl0.y) / (pxl1.x - pxl0.x);
	x[0] = round(pxl0.x);
	y[0] = pxl0.y + grad * (x[0] - pxl0.x);
	if (floor(x[0]) <= LIM_X && floor(y[0]) <= LIM_Y &&
		x[0] >= 0 && y[0] >= 0)
		data[(int)(floor(y[0]) * width + x[0])] = rgb_to_int(pxl0.color, 1);
	y[0] += grad;
	x[1] = round(pxl1.x);
	y[1] = pxl1.y + grad * (x[1] - pxl1.x);
	if (x[1] <= LIM_X && floor(y[1]) <= LIM_Y &&
		x[1] >= 0 && y[1] >= 0)
		data[(int)(floor(y[1]) * width + x[1])] = rgb_to_int(pxl1.color, 1);
	win_nosteep(x, y, grad);
	while (++x[0] <= x[1] - 1)
	{
		pos[0] = (int)floor(y[0]) * width + x[0];
		pos[1] = pos[0] + width;
		(x[0] >= 0. && y[0] >= 0.) ? add_to_img(pos, y[0], data, pxl0) : 0;
		y[0] += grad;
	}
}
/*
** data[?] = rgb_to_int(.., ..);
** ? : position of the pixel on the char pointer that you calculate with:
**		X position * 4 + 4 * Line size * Y position.
** int	rgb_to_int(t_color color, double brightness)
** : the 3 first chars according to the color you want to get.
*/
