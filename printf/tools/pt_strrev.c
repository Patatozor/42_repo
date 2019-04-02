/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:10:11 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 15:15:54 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pt_strrev(char *str)
{
	int		i;
	int		k;

	i = -1;
	k = pt_strlen(str);
	while (++i < --k)
	{
		str[i] ^= str[k];
		str[k] ^= str[i];
		str[i] ^= str[k];
	}
	return (str);
}
