/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:58:04 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/18 11:34:54 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_X, IMG_Y);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	draw_image(&mlx->fdf, IMG_X, mlx->img.data);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr,
			WIN_X / 16, WIN_Y / 7);
}

int		close_win(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

/*
** close_win: close window by clicking on "X"
** no need to free, exit() will do it for you
*/

void	set_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_win, mlx);
}

/*
** int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
** void *param);
** "mlx.h" defines mlx_hook() in the same manner mlx_*_hook functions work.
** The event and mask values will be taken from the X11 include file X.h
** (even for MacOSX, for compatibility purposes)
*/
