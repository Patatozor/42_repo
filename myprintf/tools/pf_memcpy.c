/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:54:45 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 13:56:52 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	*pf_memset(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (n <= 0 || dst == src)
		return (dst);
	s1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (dst);
}
