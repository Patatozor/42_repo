/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_percent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:47:34 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 16:56:47 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		d_percent(t_opts opts, va_list ap)
{
	(void)opts;
	(void)ap;
	pt_putchar('%');
	return (1);
}
