#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	if (opts.length != 104 && opts.length != 208 &&
		opts.length != 108 && opts.length != 216 &&
		opts.length != 106 && opts.length != 122 &&
		opts.length != 0)
	{
		pt_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static uint64_t	get_num(uint32_t length, va_list ap)
{
	uint64_t	n;

	n = 0;
	if (length == 0 || length == 104 || length == 208 || length == 108)
		n = va_arg(ap, uint32_t);
	else if (length == 216)
		n = va_arg(ap, uint64_t);
	else if (length == 106)
		n = va_arg(ap, uintmax_t);
	else if (length == 122)
		n = va_arg(ap, size_t);
	return (n);
}

static char		*pad_precision(char *s, int n, int precision)
{
	int		len;
	char	*str;

	len = pt_strlen(s);
	if (len >= precision && !(precision == 0 && n == 0))
		return (s);
	NULL_CHECK(!(str = (char*)pt_memalloc(precision + 1)));
	str = pt_memset(str, '0', precision);
	str[precision] = '\0';
	if (precision > len)
		pt_memcpy(&str[precision - len], &s[0], len);
	free(s);
	return (str);
}

static char		*padding(char *s, t_opts opts)
{
	char	*str;
	int		len;
	int		l;

	len = pt_strlen(s) + ((opts.flags.plus || opts.flags.space) ? 1 : 0);
	len = ((uint32_t)len > opts.width ? len : opts.width);
	NULL_CHECK(!(str = (char*)pt_memalloc(len + 1)));
	pt_memset(str, (opts.flags.zero && opts.precision == -1 ? '0' : ' '), len);
	str[len] = '\0';
	l = pt_strlen(s);
	if (opts.flags.minus)
		pt_strncpy(str, s, l);
	else
		pt_strncpy(&str[len - l], s, l);
	if (opts.flags.plus)
		str[(opts.flags.zero ? 0 : len - l - 1)] = '+';
	else if (opts.flags.space)
		str[0] = ' ';
	free(s);
	return (str);
}

int				d_ud(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pt_uitoa(n);
	s = pad_precision(s, n, opts.precision);
	s = padding(s, opts);
	pt_putstr(s);
	len = pt_strlen(s);
	free(s);
	return (len);
}
