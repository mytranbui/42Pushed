/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:59:58 by mbui              #+#    #+#             */
/*   Updated: 2020/01/15 13:55:25 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_replace_chr(char const *s, int c1, int c2)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c1)
			*((char *)s + i) = c2;
		++i;
	}
	return ((char *)s);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		end;
	char		tmp[ft_strlen(s) + 1];
	char		**arr;

	i = 0;
	j = 0;
	end = ft_strlen(s);
	ft_bzero(tmp, sizeof(tmp));
	ft_strcpy(tmp, s);
	ft_replace_chr(tmp, c, '\0');
	arr = (char **)malloc(sizeof(*arr) * (end));
	while (i < end && s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		arr[j] = ft_strdup(tmp + i);
		++j;
		while (tmp[i] != '\0')
			++i;
		++i;
	}
	arr[j] = NULL;
	return (arr);
}
