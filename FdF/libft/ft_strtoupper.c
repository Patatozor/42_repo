/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 06:26:39 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/26 06:27:02 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char const *s)
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
		if (s[len] >= 'a' && s[len] <= 'z')
			str[len] = s[len] - 32;
		else
			str[len] = s[len];
	}
	return (str);
}
