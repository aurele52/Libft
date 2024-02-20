/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:28:16 by audreyer          #+#    #+#             */
/*   Updated: 2021/11/29 22:51:10 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static char	*ft_remp(char *str, int n, int i) {
	str[i + 1] = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

static char	*ft_crea(int n, int i, int negative) {
	char	*str;

	if (n == 0)
		return (ft_strdup("0", 0));
	str = malloc(sizeof(char) * (i + negative + 1));
	if (!(str))
		return (0);
	if (negative == 1)
		str[0] = '-';
	return (ft_remp(str, n, i + negative - 1));
}

char	*ft_itoa(int n) {
	int	nb;
	int	i;
	int negative;

	i = 0;
	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648", 0));
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (ft_crea(n, i, negative));
}
