/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:15:32 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/18 11:19:32 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*free_mlx(t_mlx *mlx)
{
	if (mlx->fdf)
		lstdel_fdf(&mlx->fdf);
	if (mlx->original)
		lstdel_fdf(&mlx->original);
	free(mlx);
	return (mlx = NULL);
}

t_mlx	*mlx_start(char *av)
{
	t_mlx	*mlx;
	int		fd;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))) ||
	!(mlx->fdf = (t_pxl*)malloc(sizeof(t_pxl))) ||
	!(mlx->original = (t_pxl*)malloc(sizeof(t_pxl))))
		return (NULL);
	mlx->fdf->zoom = 15;
	mlx->proj = "ISO";
	mlx->cam.x = 0;
	mlx->cam.y = -100;
	mlx->cam.z = 200;
	mlx->cam.col_opt = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (free_mlx(mlx));
	if (read_store(fd, &mlx->fdf, mlx->cam.col_opt) == -1)
		return (free_mlx(mlx));
	if (!(copy_fdf(&mlx->fdf, &mlx->original)))
		return (free_mlx(mlx));
	return (mlx);
}
