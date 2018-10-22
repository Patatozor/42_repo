/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:24:51 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/24 16:26:11 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimchar(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!*s)
		return ((char *)s);
	len = ft_strlen(s) - 1;
	while (s[i] && (s[i] == c) && i < len)
		i++;
	while (s[len] && s[len] == c && len >= i)
		len--;
	if (!(str = malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	while (s[i] && i <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
