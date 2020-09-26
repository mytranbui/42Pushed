/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 11:55:47 by mbui              #+#    #+#             */
/*   Updated: 2019/04/01 12:16:51 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;

	i = nb - 1;
	if (nb >= 1 && nb < 13)
	{
		while (i >= 1)
		{
			nb = nb * i;
			i--;
		}
		return (nb);
	}
	else if (nb == 0)
		return (1);
	else
		return (0);
}