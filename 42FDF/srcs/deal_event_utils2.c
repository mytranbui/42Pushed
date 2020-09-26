/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_event_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:13:17 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/15 15:06:56 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_alt(t_pxl **start, t_pxl **start_or, int i)
{
	t_pxl	*tmp;
	t_pxl	*tmp_or;

	tmp = *start;
	tmp_or = *start_or;
	while (tmp)
	{
		if (tmp_or->z > start_or[0]->zoom)
			tmp->y -= i;
		tmp = tmp->nxt;
		tmp_or = tmp_or->nxt;
	}
}
