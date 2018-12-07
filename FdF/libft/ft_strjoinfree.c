/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 01:22:05 by rfumeron          #+#    #+#             */
/*   Updated: 2018/10/22 00:12:52 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s3;

	s3 = NULL;
	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		if ((s3 = malloc(sizeof(char) * (s1len + s2len + 1))))
		{
			ft_memcpy(s3, s1, s1len);
			ft_memcpy(s3 + s1len, s2, s2len);
			s3[s1len + s2len] = 0;
		}
		free(s1);
		free(s2);
	}
	return (s3);
}
