/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:58:04 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 10:06:25 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_window(t_mlx *mlx)
{
	int		spc;
	int		col;
	char	*str[8];
	int		i;

	i = 0;
	spc = 12;
	col = WHITE;
	str[0] = "projection          : I/P/O";
	str[1] = "zoom                : scroll";
	str[2] = "move                : arrows";
	str[3] = "rotate              : R";
	str[4] = "color(except ORTHO) : C";
	str[5] = "reset               : space";
	str[6] = "altitude(ISO)       : +/-";
	str[7] = NULL;
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, 5, col, "FDF");
	while (i < 4)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 5, spc += 18, col, str[i++]);
	spc = 12;
	while (i < 7)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 400, spc += 18, col,
			str[i++]);
	spc = (WIN_X - 125);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, spc, 5, col, "ESC to quit");
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac == 2)
	{
		if (!(mlx = mlx_start(av[1])))
			return (-1);
		mlx->mlx_ptr = mlx_init();
		if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "FDF")))
			exit(EXIT_FAILURE);
		projection(mlx->proj, &mlx->fdf, mlx->cam);
		mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_X, IMG_Y);
		mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
				&mlx->img.size_l, &mlx->img.endian);
		draw_image(&mlx->fdf, IMG_X, mlx->img.data);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr,
				WIN_X / 16, WIN_Y / 7);
		create_window(mlx);
		set_hooks(mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	ft_putendl("usage: ./fdf <file>");
	return (0);
}
