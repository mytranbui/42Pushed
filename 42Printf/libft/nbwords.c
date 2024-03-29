/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbwords.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:39:09 by mbui              #+#    #+#             */
/*   Updated: 2019/11/21 14:46:37 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbwords(char const *s, char c)
{
	int	tmp;
	int	n;

	tmp = 0;
	n = 0;
	while (*s)
	{
		*s == c && tmp == 1 ? tmp = 0 : tmp;
		if (*s != c && tmp == 0)
		{
			tmp = 1;
			n++;
		}
		s++;
	}
	return (n);
}
