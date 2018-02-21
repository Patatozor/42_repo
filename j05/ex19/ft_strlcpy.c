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
	unsigned int	j;
	unsigned int	index;

	j = 0;
	index = 0;
	while (dest[index])
		index++;
	while (src[j] != '\0' && j < size)
	{
		dest[index + j] = src[j];
		j++;
	}
	dest[index + j] = '\0';
	i = 0;
	while (src[index])
		i++;
	return (index);
}
