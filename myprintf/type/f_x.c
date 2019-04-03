#include "../inc/ft_printf.h"

static void		error_check(t_opts opts)
{
	(void)opts;
}

static uint64_t	get_num(int length, va_list ap)
{
	uint64_t	n;

	n = 0;
	if (length == 0 || length == 10 || length == 20 || length == 11)
		n = va_arg(ap, int);
	else if (length == 22)
		n = va_arg(ap, uint64_t);
	return (n);
}

static char		*pound(char *s)
{
	int		len;
	char	*str;

	len = pf_strlen(s);
	if (!(str = (char*)pf_strnew(len + 2)))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	pf_strncpy(&str[2], s, len);
	free(s);
	return (str);
}

static char		*padding(char *s, int len, t_opts opts)
{
	char	*str;

	if (!(str = (char*)pt_strnew(opts.width)))
		return (NULL);
	pf_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		pf_strncpy(str, s, len);
	else
		pf_strncpy(&str[opts.width - len], s, len);
	free(s);
	return (str);
}

int				f_x(t_opts opts, va_list ap)
{
	uint64_t	n;
	char		*s;
	int			len;

	error_check(opts);
	n = get_num(opts.length, ap);
	s = pf_itoh(n, 0);
	if (opts.flags.pound && n)
		s = pound(s);
	len = pf_strlen(s);
	if (opts.width > len)
		s = padding(s, len, opts);
	pf_putstr(s);
	len = pf_strlen(s);
	free(s);
	return (len);
}
