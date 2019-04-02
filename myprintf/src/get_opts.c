/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:34:05 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 17:13:23 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_flags	get_flags(char **str)
{
	t_flags flags;

	flags.pound = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	while (**str != '\0')
	{
		if (**str == '#')
			flags.pound = 1;
		else if (**str == '0')
			flags.zero = 1;
		else if (**str == '-')
			flags.minus = 1;
		else if (**str == '+')
			flags.plus = 1;
		else if (**str == ' ')
			flags.space = 1;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

static int		get_width(char **str, va_list ap)
{
	int	w;

	w = 0;
	if (**str >= '0' && **str <= '9')
	{
		w = pf_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		w = va_arg(ap, int);
		(*str)++;
	}
	return (w);
}

static int		get_precision(char **str, va_list ap)
{
	int	p;

	p = -1;
	if (**str == '.')
	{
		p = 0;
		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			p = pf_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			p = va_arg(ap, int);
			(*str)++;
		}
	}
	return (p);
}

static int		get_length(char **str)
{
	int	l;

	l = 0;
	if (**str == 'h' && *(*str + 1) != 'h')
		l = 10;
	else if (**str == 'h' && *(*str + 1) == 'h')
		l = 20;
	else if (**str == 'l' && *(*str + 1) != 'l')
		l = 11;
	else if (**str == 'l' && *(*str + 1) == 'l')
		l = 22;
	if (l > 0)
		(*str) += (l >= 12 ? 2 : 1);
	return (l);
}

t_opts			get_opts(char **str, va_list ap)
{
	t_opts opts;

	opts.flags = get_flags(str);
	opts.width = get_width(str, ap);
	opts.precision = get_precision(str, ap);
	opts.length = get_length(str);
	return (opts);
}
