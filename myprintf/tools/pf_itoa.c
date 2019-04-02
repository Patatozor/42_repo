/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:16:09 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 15:20:11 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pf_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = (n >= 0 ? 1 : -1);
	len = pf_placevalue(n) + (sign >= 0 ? 0 : 1);
	if (!(str = (char *)pf_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len--;
	while (n)
	{
		str[len] = n % 10 * sign + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		str[len] = '-';
	return (str);
}
