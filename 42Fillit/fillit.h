/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:20:25 by mbui              #+#    #+#             */
/*   Updated: 2019/10/18 09:37:05 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# define MAX_READ 545

/*
** fcntl.h for using the fct open()
** MAX_READ: max number of char the file can contain
*/

typedef struct	s_tetro
{
	char			**tab;
	char			let;
	int				pos[4][2];
	double			nb;
	struct s_tetro	*next;
}				t_tetro;

/*
** tab: used to store the tetrominoes
** let: letter assigned to each tetro in order to print in the solution
** pos[4][2]: coords of the 4 '#' on each block of 20 char
** nb: total number of tetro
** *next: points to the next tetro
*/

char			*ft_read(int fd);
int				link_count(char *file);
int				check_link(int *n, int *i);
t_tetro			*stock(char *file);
t_tetro			*newt(char *file, int *j, char lettre);
int				get_coord(t_tetro *newt);
t_tetro			*lstdel_tetro(t_tetro **head);
char			**init_map(int size);
char			**solver(t_tetro *tetro, int size, char **map, int p[2]);
int				find_space(char **map, int pos[4][2], int p[2], int size);
void			add_tetro(t_tetro *tetro, char **map, int i, int j);
int				check_map(char **map, int *i, int *j, int size);
void			print_and_free(t_tetro **head, char **map);
int				get_solv(t_tetro *tetro);

/*
** check_link: check the number of links between each block of a tetro
** stock: store each tetro in the linked list
** newt: initialize a node of the linked list
** get_coord: get the coord of each block of a tetro on a tab
** init_map: initialize a map filled with '.'
** solver: use of backtracking to get the solution
*/
#endif
