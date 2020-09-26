/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:50:46 by mbui              #+#    #+#             */
/*   Updated: 2019/09/23 18:12:48 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double nb)
{
	double tmp;
	double sqrt;

	tmp = 0;
	sqrt = nb / 2;
	while (sqrt != tmp)
	{
		tmp = sqrt;
		sqrt = (nb / tmp + tmp) / 2;
	}
	return (sqrt);
}
