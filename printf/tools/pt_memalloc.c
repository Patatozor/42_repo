/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:48:59 by jochang           #+#    #+#             */
/*   Updated: 2019/04/02 13:52:44 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	*pt_memalloc(size_t size)
{
	void	*temp;

	temp = (void*)malloc(size);
	NULL_CHECK(!temp);
	pt_bzero(temp, size);
	return (temp);
}
