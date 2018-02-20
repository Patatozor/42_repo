/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:27:53 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/14 16:56:36 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_my_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		dest_len;

	i = 0;
	dest_len = ft_my_strlen(dest);
	while (i < nb && *src != '\0')
	{
		*(dest + dest_len + i) = *src;
		i++;
		src++;
	}
	while (i++ < nb)
		*(dest + dest_len + i) = '\0';
	return (dest);
}
