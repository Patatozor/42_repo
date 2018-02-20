/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:49:23 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/14 15:28:41 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = ft_my_strlen(dest);
	i = 0;
	while (*src != '\0')
	{
		*(dest + dest_len + i) = *src;
		src++;
		i++;
	}
	return (dest);
}
