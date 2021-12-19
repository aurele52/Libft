/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:23:35 by audreyer          #+#    #+#             */
/*   Updated: 2021/11/29 16:56:52 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (start + len > ft_strlen(s))
		len--;
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	s = start + s;
	i = 0;
	str[len] = 0;
	while (len > 0)
	{
		str[len - 1] = s[len - 1];
		len--;
	}
	return (str);
}
