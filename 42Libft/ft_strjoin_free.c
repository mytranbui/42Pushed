/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:43:22 by mbui              #+#    #+#             */
/*   Updated: 2019/06/28 16:46:03 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free)
{
	char			*d;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(d = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(d, s1);
	ft_strcat(d, s2);
	if (free == 1)
		ft_strdel(&s1);
	if (free == 2)
		ft_strdel(&s2);
	if (free == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (d);
}
