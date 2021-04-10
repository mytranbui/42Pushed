/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:20:23 by mbui              #+#    #+#             */
/*   Updated: 2020/11/11 19:29:04 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

double	ft_pow(double x, double y)
{
	double	tmp;

	tmp = x;
	if (y < 0)
		return (0);
	if (y == 0 || x == 1)
		return (1);
	while (y > 1)
	{
		x *= tmp;
		y--;
	}
	return (x);
}
