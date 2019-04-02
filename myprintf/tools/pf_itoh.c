/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:28:20 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 17:08:19 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pf_itoh(int n, int caps)
{
	int		i;
	char	*s;
	char	*hex;

	if (!(s = (char*)pt_strnew(8)))
		return (NULL);
	hex = (caps ? "0123456789ABCDEF" : "0123456789abcdef");
	i = (n == 0 ? 1 : 0);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i] = hex[n & 15];
		n >>= 4;
		i++;
	}
	s[i] = '\0';
	pf_strrev(s);
	return (s);
}
