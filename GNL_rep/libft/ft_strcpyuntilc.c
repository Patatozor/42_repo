/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyuntilc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 01:17:23 by rfumeron          #+#    #+#             */
/*   Updated: 2018/10/22 01:35:09 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyuntilc(char *dst, const char *src, char c)
{
	size_t	i;

	i = ft_strlenuntilc(src, c);
	if (!(dst = malloc(sizeof(char) * i)))
		return (NULL);
	dst[i] = '\0';
	dst = ft_strncpy(dst, src, i);
	return (dst);
}
