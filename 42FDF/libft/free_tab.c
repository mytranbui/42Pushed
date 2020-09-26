/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:52:08 by mbui              #+#    #+#             */
/*   Updated: 2019/10/18 09:12:01 by agomes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a tab and a index i indicating the END of the tab
** frees tab
*/

char	**free_tab(char **tab, int i)
{
	while (i >= 0)
		ft_strdel(&tab[i--]);
	free(tab);
	return (NULL);
}
