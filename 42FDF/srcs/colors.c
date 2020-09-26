/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:20:12 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 14:24:49 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned char	split_color_str(char *val, char c)
{
	char	color[3];

	color[2] = 0;
	if (c == 'r')
	{
		color[0] = val[0];
		color[1] = val[1];
	}
	if (c == 'g')
	{
		color[0] = val[2];
		color[1] = val[3];
	}
	if (c == 'b')
	{
		color[0] = val[4];
		color[1] = val[5];
	}
	return ((unsigned char)ft_atoi_base(&color[0], 16));
}

/*
** each primary color is composed of 2 chars (ex: 0xff)
*/

t_color			get_rgb(char *val)
{
	int		i;
	t_color	color;

	i = -1;
	if (val[0] == '-' || val[0] == '+')
		i++;
	color.red = 0xff;
	color.green = 0xff;
	color.blue = 0xff;
	while (val[++i])
		if (!(val[i] >= '0' && val[i] <= '9'))
		{
			if (val[i + 2] == 'x')
			{
				color.red = split_color_str(&val[i + 3], 'r');
				color.green = split_color_str(&val[i + 3], 'g');
				color.blue = split_color_str(&val[i + 3], 'b');
				return (color);
			}
		}
	return (color);
}

/*
** split_color_str: split value of rgb into 3 values (red, green, blue)
*/

int				rgb_to_int(t_color color, double brightness)
{
	unsigned int	rgb;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = color.red * brightness;
	g = color.green * brightness;
	b = color.blue * brightness;
	rgb = ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
	return (rgb);
}

void			init_gradient(t_pxl **start)
{
	t_pxl	*pxl;
	int		lvl;
	int		lvlmax;

	pxl = *start;
	lvlmax = 0;
	while (pxl)
	{
		if (lvlmax < (int)(pxl->z / start[0]->zoom))
			lvlmax = (int)(pxl->z / start[0]->zoom);
		pxl = pxl->nxt;
	}
	pxl = *start;
	while (pxl)
	{
		lvl = (int)(pxl->z / start[0]->zoom) - 1;
		pxl->color.red = RED + ((RED2 - RED) / lvlmax) * lvl;
		pxl->color.green = GREEN + ((GREEN2 - GREEN) / lvlmax) * lvl;
		pxl->color.blue = BLUE + ((BLUE2 - BLUE) / lvlmax) * lvl;
		pxl = pxl->nxt;
	}
}

/*
** lvlmax: the highest altitude of the map
** lvl: the current altitude of the pixel
*/
