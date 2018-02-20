/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:17:01 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/20 17:00:00 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	src_len;
	unsigned int	char_len;
	unsigned int	index;

	index = 0;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	char_len = (src_len > n) ? (n) : (n - src_len);
	while (index < char_len)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}
