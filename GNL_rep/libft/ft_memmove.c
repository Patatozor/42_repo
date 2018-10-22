/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:47:43 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/18 15:00:17 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (src < dst)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
