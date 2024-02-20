/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:45:25 by audreyer          #+#    #+#             */
/*   Updated: 2021/11/29 19:31:28 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str) {
	int	i;
	int	negative;
	int	res;

	i = 0;
	res = 0;
	negative = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0' && str[i]) {
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}
