/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:59:23 by mbui              #+#    #+#             */
/*   Updated: 2020/01/15 13:55:48 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabcpy(char **tab, size_t size)
{
	char	**new;
	size_t	j;
	size_t	i;

	j = -1;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++j < size)
	{
		if (!(new[j] = (char*)ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		i = -1;
		while (++i < size)
			new[j][i] = tab[j][i];
	}
	new[j] = 0;
	return (new);
}
