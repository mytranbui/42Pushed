/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-a <agomes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:02:31 by agomes-a          #+#    #+#             */
/*   Updated: 2020/01/15 13:55:03 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*free_lst(t_list **begin)
{
	t_list	*curr;
	t_list	*next;

	curr = *begin;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*begin = NULL;
	return (NULL);
}
