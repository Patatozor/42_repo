/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:21:06 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 15:24:25 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pt_itoo(uint64_t n)
{
	int		i;
	char	*s;
	char	*oct;

	if (!(s = (char *)pf_strnew(12)))
		return (NULL);
	oct = "01234567";
	i = (n == 0 ? 1 : 0);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i] = oct[n & 7];
		n >>= 3;
		i++;
	}
	s[i] = '\0';
	pf_strrev(s);
	return (s);
}
