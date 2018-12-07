/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:25:34 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/18 16:00:10 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	nb;
	int					signe;

	nb = 0;
	while (*str == 32 || *str == 9 || *str == 11 || *str == 10 || *str == 13
			|| *str == 12)
		str++;
	signe = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + *str++ - '0';
	if (nb > 9223372036854775807ul && signe == 1)
		return (-1);
	if (nb > 9223372036854775808ul && signe == -1)
		return (0);
	return ((int)nb * signe);
}
