/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:20:55 by mbui              #+#    #+#             */
/*   Updated: 2019/04/01 14:26:21 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int i;

	if (min >= max)
		range = (int *)0;
	else
	{
		range = (int *)malloc(sizeof(int) * (max - min));
		i = 0;
		while (min < max)
		{
			range[i] = min;
			i++;
			min++;
		}
		range[i] = 0;
	}
	return (range);
}
