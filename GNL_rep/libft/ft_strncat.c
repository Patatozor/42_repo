/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:55:26 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/18 16:17:41 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		dest_size;

	i = 0;
	dest_size = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[dest_size] = s2[i];
		dest_size++;
		i++;
	}
	s1[dest_size] = '\0';
	return (s1);
}
