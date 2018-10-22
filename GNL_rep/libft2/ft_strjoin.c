/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:02:15 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/23 17:45:53 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	int		i;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	if (!(s3 = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_memcpy(s3, s1, s1len);
	ft_memcpy(s3 + s1len, s2, s2len);
	s3[s1len + s2len] = '\0';
	return (s3);
}
