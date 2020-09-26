/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:00:49 by mbui              #+#    #+#             */
/*   Updated: 2019/06/10 11:18:06 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(int n, size_t len)
{
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*r;
	size_t			len;
	unsigned int	nb;

	nb = n;
	len = 1;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	len = size(n, len);
	if (!(r = ft_strnew(len)))
		return (NULL);
	while (nb / 10 != 0)
	{
		r[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	r[len - 1] = nb + 48;
	if (len == 2)
		r[0] = '-';
	return (r);
}
