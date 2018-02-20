/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:13:55 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/20 16:51:30 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strstr(char *str, char *tofind)
{
	int	str_len;
	int	tofind_len;
	int	index;
	int pos;

	index = 0;
	pos = 0;
	str_len = ft_strlen(str);
	tofind_len = ft_strlen(tofind);
	if (tofind_len > str_len)
		return (0);
	if (!tofind_len)
		return (str);
	while (pos < str_len + 1&& index < tofind_len)
	{
		if (*str++ == *(tofind + index))
			index++;
		else
			index = 0;
		pos++;
	}
	if (pos == str_len + 1)
		return (0);
	else
		return (str - tofind_len);
}

int		main(int argc, char **argv)
{
	if (argc)
		printf("%s\n", ft_strstr(argv[1], argv[2]));
	return (0);
}
