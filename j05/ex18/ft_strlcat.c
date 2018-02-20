/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:18:32 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/14 16:54:50 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_my_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dest_len;
	unsigned int src_len;

	i = 0;
	dest_len = ft_my_strlen(dest);
	src_len = ft_my_strlen(src);
	if (dest_len >= size)
	{
		return (src_len + size);
	}
	while ((i < (size - dest_len - 1)) && *src != '\0')
	{
		*(dest + dest_len + i) = *src;
		i++;
		src++;
	}
	*(dest + dest_len + i) = '\0';
	return (dest_len + src_len);
}
