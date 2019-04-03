#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	if (opts.length != 10 && opts.length != 20 &&
		opts.length != 11 && opts.length != 22 &&
		opts.length != 0)
	{
		pf_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static int64_t	get_num(unsigned int length, va_list ap)
{
	int64_t	n;

	n = 0;
	if (length == 0 || length == 10 || length == 20 || length == 11)
		n = va_arg(ap, int);
	else if (length == 22)
		n = va_arg(ap, int64_t);
	return (n);
}

static char		*pad_precision(char *s, int n, int precision)
{
	int		len;
	char	*str;

	len = pf_strlen(s);
	if (len >= precision && !(precision == 0 && n == 0))
		return (s);
	if (!(str = (char*)pt_memalloc(precision + 1)))
		return (NULL);
	str = pf_memset(str, '0', precision);
	str[precision] = '\0';
	if (precision > len)
		pf_memcpy(&str[precision - len], &s[0], len);
	free(s);
	return (str);
}

static char		*padding(char *s, t_opts opts, int neg)
{
	char	*str;
	int		len;
	int		l;

	len = pf_strlen(s) + ((neg || opts.flags.plus || opts.flags.space) ? 1 : 0);
	len = (len > opts.width ? len : opts.width);
	if (!(str = (char*)pt_memalloc(len + 1)))
		return (NULL);
	pf_memset(str, (opts.flags.zero && opts.precision == -1 ? '0' : ' '), len);
	str[len] = '\0';
	l = pf_strlen(s);
	if (opts.flags.minus)
		pf_strncpy(&str[neg], s, l);
	else
		pf_strncpy(&str[len - l], s, l);
	if (neg)
		str[(opts.flags.minus || opts.flags.zero ? 0 : len - l - 1)] = '-';
	else if (opts.flags.plus)
		str[(opts.flags.minus || opts.flags.zero ? 0 : len - l - 1)] = '+';
	else if (opts.flags.space)
		str[0] = ' ';
	free(s);
	return (str);
}

int				f_d(t_opts opts, va_list ap)
{
	int64_t	n;
	char	*s;
	int		len;
	int		neg;

	error_check(opts);
	n = get_num(opts.length, ap);
	neg = (n < 0 ? 1 : 0);
	s = pf_itoa_abs(n);
	s = pad_precision(s, n, opts.precision);
	s = padding(s, opts, neg);
	pf_putstr(s);
	len = pf_strlen(s);
	free(s);
	return (len);
}
