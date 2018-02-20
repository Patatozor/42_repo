/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:55:42 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/14 17:16:03 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	index;

	src_len = 0;
	index = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (index < (size - 1) && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	*(dest + index + 1) = '\0';
	return (src_len);
}
