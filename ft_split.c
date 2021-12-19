/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:59:57 by audreyer          #+#    #+#             */
/*   Updated: 2021/12/05 18:18:21 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wcount(char const *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			wcount++;
		i++;
	}
	return (wcount);
}

static int	ft_wlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static char	**ft_free(char **str, int a)
{
	while (a > 0)
		free(str[a--]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		a;
	char	**str;

	a = 0;
	str = malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!str)
		return (0);
	str[ft_wcount(s, c)] = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			str[a] = ft_substr(s, 0, (ft_wlen(s, c)));
			if (!str[a])
				return (ft_free(str, a));
			a++;
		}
		s = s + ft_wlen(s, c);
	}
	return (str);
}
