/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:58:24 by agomes-a          #+#    #+#             */
/*   Updated: 2019/11/13 11:58:53 by agomes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(double nb, double power)
{
	if (power < 0.0)
		return (0);
	if (power == 0.0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}
