/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:00:12 by mbui              #+#    #+#             */
/*   Updated: 2019/04/03 11:19:35 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display_file(char *name)
{
	int		fd;
	char	buf[1];

	fd = open(name, O_RDONLY);
	while (read(fd, buf, sizeof(buf)))
		write(1, buf, sizeof(buf));
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		display_file(argv[1]);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
