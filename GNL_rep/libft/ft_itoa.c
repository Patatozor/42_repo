/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:46:42 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/17 14:57:51 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions calculates 4 counters
** counters[0] is the max divisor
** counters[1] is the number of bytes to allocate for the string in ft_itoa
** counters[2] is whether we need another byte for the '-' or not
** counters[3] is the absolute value of n
*/

static void	ft_counters(int n, unsigned int *counters)
{
	counters[0] = 1;
	counters[1] = 1;
	counters[2] = (n >= 0) ? 0 : 1;
	counters[3] = (n >= 0) ? n : -n;
	while (counters[3] / counters[0] >= 10)
	{
		counters[0] *= 10;
		counters[1]++;
	}
}

char		*ft_itoa(int n)
{
	unsigned int	i[4];
	unsigned int	j;
	char			*ret;

	ft_counters(n, i);
	j = 0;
	if (!(ret = malloc(sizeof(char) * (i[1] + i[2] + 1))))
		return (NULL);
	if (i[2] == 1)
		ret[j++] = '-';
	while (i[0] >= 1)
	{
		ret[j++] = i[3] / i[0] + '0';
		i[3] = i[3] % i[0];
		i[0] /= 10;
	}
	ret[j] = '\0';
	return (ret);
}
