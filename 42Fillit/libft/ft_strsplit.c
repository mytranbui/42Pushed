/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:59:58 by mbui              #+#    #+#             */
/*   Updated: 2019/10/17 14:27:06 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nstrings(char const *s, char c)
{
	int	tmp;
	int	n;

	tmp = 0;
	n = 0;
	while (*s)
	{
		if (*s == c && tmp == 1)
			tmp = 0;
		if (*s != c && tmp == 0)
		{
			tmp = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static int	lstring(char const *s, int start, char c)
{
	int	end;

	end = 0;
	while (s[start + end] != c)
		end++;
	return (end);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (s == 0 || !(tab = (char **)malloc(sizeof(char *) * nstrings(s, c) + 1)))
		return (NULL);
	while (j < nstrings(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			l = lstring(s, i, c);
			if (!(tab[j] = ft_strsub(s, i, l)))
				return (free_tab(tab, j));
			i = i + l;
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
