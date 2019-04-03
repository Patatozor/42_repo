/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_u.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:02:45 by jochang           #+#    #+#             */
/*   Updated: 2018/08/22 18:26:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	if (opts.length != 10 && opts.length != 20 &&
		opts.length != 11 && opts.length != 22 &&
		opts.length != 0)
	{
		pt_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static uint64_t	get_num(int length, va_list ap)
{
	uint64_t	n;

	n = 0;
	if (length == 0 || length == 10 || length == 20)
		n = va_arg(ap, unsigned int);
	else if (length == 11 || length == 22)
		n = va_arg(ap, uint64_t);
	return (n);
}

static char		*pad_precision(char *s, uint64_t n, int precision)
{
	int		len;
	char	*str;

	len = pt_strlen(s);
	if (len >= precision && !(precision == 0 && n == 0))
		return (s);
	if (!(str = (char*)pf_strnew(precision)))
		return (NULL);
	str = pf_memset(str, '0', precision);
	str[precision] = '\0';
	if (precision > len)
		pf_memcpy(&str[precision - len], s, len);
	free(s);
	return (str);
}

static char		*padding(char *s, t_opts opts)
{
	char	*str;
	int		len;
	int		l;

	len = pf_strlen(s) + ((opts.flags.plus || opts.flags.space) ? 1 : 0);
	len = (len > opts.width ? len : opts.width);
	if (!(str = (char*)pt_strnew(len)))
		return (NULL);
	pf_memset(str, ((opts.flags.zero && !opts.flags.minus) ?
				'0' : ' '), len);
	str[len] = '\0';
	l = pf_strlen(s);
	if (opts.flags.minus)
		pf_strncpy(str, s, l);
	else
		pf_strncpy(&str[len - l], s, l);
	free(s);
	return (str);
}

int				f_u(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pt_uitoa(n);
	s = pad_precision(s, n, opts.precision);
	s = padding(s, opts);
	pf_putstr(s);
	len = pf_strlen(s);
	free(s);
	return (len);
}
