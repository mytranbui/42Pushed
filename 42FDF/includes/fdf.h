/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:27:55 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/17 14:24:36 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "key_macos.h"
# include <math.h>
# include <fcntl.h>

/*
** "key_macos.h" for key and mouse codes
** <math.h> for round() and floor()
** <fcntl.h> for open()
*/

# define WIN_MAX 2000
# define WIN_X 1500
# define WIN_Y 1000
# define IMG_X WIN_X - WIN_X / 16
# define IMG_Y WIN_Y - WIN_Y / 7
# define LIM_X WIN_X - WIN_X / 15
# define LIM_Y WIN_Y - WIN_Y / 6

# define WHITE 0xffffff
# define RED 229
# define GREEN 0
# define BLUE 154
# define RED2 0
# define GREEN2 191
# define BLUE2 62
# define DEG_30 0.523599
# define DEG_90 1.5708

typedef	struct	s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_color;

typedef	struct	s_pxl
{
	double			x;
	double			y;
	double			z;
	t_color			color;
	int				line;
	int				zoom;
	struct s_pxl	*nxt;
}				t_pxl;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef	struct	s_cam
{
	int	x;
	int	y;
	int	z;
	int	col_opt;
}				t_cam;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_pxl	*fdf;
	t_pxl	*original;
	char	*proj;
	t_img	img;
	t_cam	cam;
}				t_mlx;

/*
** void *mlx_ptr & void *win_ptr: store data of the graphical window
** t_img img: store variables needed to get the image's char pointer
** no need of initializing the variables because you only pass their address
** in the function, it will do it for you.
** char *img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
** data is int* instead of a char* because it's easier to store all the colors,
** alpha(R,G,B, alpha), so 4 char for one pixel which is the same size as an int
*/

void			create_window(t_mlx *mlx);

/*
** all_init.c
*/
t_mlx			*mlx_start(char	*av);
t_mlx			*free_mlx(t_mlx *mlx);

/*
** store.c
*/
int				read_store(int fd, t_pxl **start, int col_opt);
int				storing(t_pxl **pxl, char **vals, int y, int col_opt);
int				lstdel_fdf(t_pxl **head);
t_pxl			*copy_fdf(t_pxl **fdf, t_pxl **start);
void			copy_next(t_pxl *copy, t_pxl *tmp);

/*
** draw.c & draw_start.c
*/
void			draw_image(t_pxl **start, int width, int *data);
void			draw_line(t_pxl pxl0, t_pxl pxl1, int width, int *data);
void			init_pxl(t_pxl *pxl0, t_pxl *pxl1, int steep);
void			steep_line(t_pxl pxl0, t_pxl pxl1, int width, int *data);
void			nosteep_line(t_pxl pxl0, t_pxl pxl1, int width, int *data);
void			win_steep(double x[2], double y[2], double grad);
void			win_nosteep(double x[2], double y[2], double grad);
void			add_to_img(int pos[2], double y, int *data, t_pxl pxl0);

/*
** projections.c
*/
void			projection(char	*proj, t_pxl **fdf, t_cam cam);
void			calc_iso(t_pxl **start, t_cam cam);
void			calc_pers(t_pxl **start, t_cam cam);
void			calc_ortho(t_pxl **start, t_cam cam);
void			turn_pos(t_pxl **start, double minx, double miny);

/*
** colors.c
*/
void			init_gradient(t_pxl **start);
t_color			get_rgb(char *val);
unsigned char	split_color_str(char *val, char c);
int				rgb_to_int(t_color color, double brightness);

/*
** deal_mouse.c & deal_key.c & deal_events.c
*/
void			set_hooks(t_mlx *mlx);
int				key_press(int key, void *param);
int				key_press2(int key, t_mlx *mlx);
void			key_press3(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, void *param);
int				close_win(void *param);
void			change(t_mlx *mlx);

/*
** deal_event_utils.c & deal_event_utils2.c
*/
void			rotationx(t_pxl **start, double angle);
void			rotationy(t_pxl **start, double angle);
void			rotationz(t_pxl **start, double angle);
void			zoom(t_pxl **start, double mult);
void			move(t_pxl **start, int x, int y);
void			change_alt(t_pxl **start, t_pxl **start_or, int i);
#endif
