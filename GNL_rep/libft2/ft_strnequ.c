/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:50:02 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/23 17:06:36 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	ret;

	ret = 0;
	if (s1 && s2)
	{
		ret = (ft_strncmp(s1, s2, n) == 0) ? 1 : 0;
	}
	return (ret);
}
