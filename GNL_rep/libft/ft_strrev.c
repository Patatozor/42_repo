/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:48:03 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/24 18:02:25 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;
	char	buff;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (len <= 1)
		return ((char *)s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	ft_strcpy(str, s);
	while (i < len)
	{
		buff = str[i];
		str[i++] = str[len];
		str[len--] = buff;
	}
	return (str);
}
