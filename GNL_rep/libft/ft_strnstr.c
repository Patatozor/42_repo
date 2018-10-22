/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:22:38 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/26 05:28:20 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s2len;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	s2len = ft_strlen(s2);
	while (i < n && s1[i])
	{
		if (ft_strnequ(s1 + i, s2, s2len) && (i + s2len) <= n)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
