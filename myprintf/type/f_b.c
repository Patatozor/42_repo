/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:14:25 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 21:25:09 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static uint64_t	get_num(int length, va_list ap)
{
	uint64_t	n;

	n = va_arg(ap, uint32_t);
	return (n);
}

static char		*pt_itob(uint32_t n)
{
	int		i;
	char	*s;

	if (!(s = (char*)pf_strnew(32)))
		return (NULL);
	i = (n == 0 ? 1 : 0);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i] = (n & 1) + '0';
		n >>= 1;
		i++;
	}
	pf_strrev(s);
	return (s);
}

static char		*padding(char *s, int len, t_opts opts)
{
	char	*str;

	if (!(str = (char*)pf_strnew(opts.width)))
		return (NULL);
	pf_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		pf_strncpy(str, s, len);
	else
		pf_strncpy(&str[opts.width - len], s, len);
	free(s);
	return (str);
}

int				d_b(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pf_itob(n);
	len = pf_strlen(s);
	if (opts.width > len)
		s = padding(s, len, opts);
	pf_putstr(s);
	len = pf_strlen(s);
	free(s);
	return (len);
}
