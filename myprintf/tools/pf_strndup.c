/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:57:16 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 15:20:40 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*pf_strndup(const char *src, size_t len)
{
	char *str;

	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	str = pf_strncpy(str, src, len);
	str[len] = '\0';
	return (str);
}
