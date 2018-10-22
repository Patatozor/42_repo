/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:37:15 by rfumeron          #+#    #+#             */
/*   Updated: 2018/10/22 00:11:10 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(newstr, (int)'\0', size + 1);
	return (newstr);
}
