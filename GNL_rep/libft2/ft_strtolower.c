/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 06:18:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/26 06:23:56 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char const *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	len = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (s[len] >= 'A' && s[len] <= 'Z')
			str[len] = s[len] + 32;
		else
			str[len] = s[len];
	}
	return (str);
}
