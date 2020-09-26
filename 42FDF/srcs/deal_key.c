/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:36:02 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/18 11:19:27 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_press2(int key, t_mlx *mlx)
{
	lstdel_fdf(&mlx->fdf);
	if (!(mlx->fdf = (t_pxl*)malloc(sizeof(t_pxl))))
		return (0);
	copy_fdf(&mlx->original, &mlx->fdf);
	if (key == K_P)
		mlx->proj = "PER";
	if (key == K_I)
		mlx->proj = "ISO";
	if (key == K_O)
	{
		mlx->cam.col_opt = 0;
		mlx->proj = "ORT";
	}
	if (key == K_C && ft_strcmp(mlx->proj, "ORT") != 0)
		mlx->cam.col_opt = mlx->cam.col_opt == 0 ? 1 : 0;
	projection(mlx->proj, &mlx->fdf, mlx->cam);
	return (1);
}

void	key_press3(int key, t_mlx *mlx)
{
	if (key == K_PAD_ADD)
		if (ft_strcmp(mlx->proj, "ISO") == 0)
			change_alt(&mlx->fdf, &mlx->original, 10);
	if (key == K_PAD_SUB)
		if (ft_strcmp(mlx->proj, "ISO") == 0)
			change_alt(&mlx->fdf, &mlx->original, -10);
}

int		key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == K_UP)
		move(&mlx->fdf, 0, -15);
	if (key == K_DOWN)
		move(&mlx->fdf, 0, 15);
	if (key == K_LEFT)
		move(&mlx->fdf, -15, 0);
	if (key == K_RIGHT)
		move(&mlx->fdf, 15, 0);
	if (key == K_R)
	{
		rotationx(&mlx->fdf, 0.1);
		rotationy(&mlx->fdf, 0.1);
		rotationz(&mlx->fdf, 0.1);
	}
	if (key == K_P || key == K_I || key == K_O || key == K_C || key == K_SPACE)
		key_press2(key, mlx);
	if (key == K_PAD_ADD || key == K_PAD_SUB)
		key_press3(key, mlx);
	change(mlx);
	if (key == K_ESC)
		exit(0);
	return (1);
}
