/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:13:47 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 15:20:28 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pf_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = -1;
	k = pt_strlen(str);
	while (++i < --k)
	{
		temp = str[k];
		str[k] = str[i];
		str[i] = temp;
	}
	return (str);
}
