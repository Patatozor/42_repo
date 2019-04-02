/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:50:52 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 13:52:42 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	*pf_memalloc(size_t size)
{
	void	*temp;

	if (!(temp = (void *)malloc(size)))
		return (NULL);
	pf_bzero(temp, size);
	return (temp);
}
