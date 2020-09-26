/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:59:47 by mbui              #+#    #+#             */
/*   Updated: 2019/06/10 11:00:42 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int value, int base)
{
	int	len;

	len = 0;
	while (value)
	{
		len++;
		value /= base;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*str_base;
	int		len;
	int		sign;

	sign = 0;
	str_base = "0123456789ABCDEF";
	len = find_size(value, base);
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	if (value == 0)
		return ("0");
	(base == 10 && value < 0) ? sign == 1 && len++ : len;
	value < 0 ? value = -value : value;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	sign ? (ret[0] = '-') : 0;
	while (value)
	{
		ret[--len] = str_base[value % base];
		value /= base;
	}
	return (ret);
}
