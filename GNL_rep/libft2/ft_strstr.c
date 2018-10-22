/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_strstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 05:19:43 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/26 05:24:47 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		s2len;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	s2len = ft_strlen(s2);
	while (s1[i])
	{
		if (ft_strnequ(s1 + i, s2, s2len))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
