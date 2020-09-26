/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_event_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:58:04 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/15 14:47:43 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (button == MOUSE_SCROLLUP)
		zoom(&mlx->fdf, 1.1);
	if (button == MOUSE_SCROLLDOWN)
		zoom(&mlx->fdf, 0.9);
	change(mlx);
	return (1);
}
