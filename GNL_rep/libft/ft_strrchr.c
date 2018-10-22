/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:48:29 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/18 16:29:17 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*temp;
	size_t	len;

	temp = NULL;
	str = (char *)s;
	len = ft_strlen(str);
	if ((char)c == '\0')
		return (str + len);
	while (*str)
	{
		if (*str == (char)c)
			temp = str;
		str++;
	}
	return (temp);
}
