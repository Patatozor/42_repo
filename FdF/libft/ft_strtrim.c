/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:03:30 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/24 15:23:45 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
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
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i < len)
		i++;
	while (s[len] && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			&& len >= i)
		len--;
	if (!(str = malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	while (s[i] && i <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
