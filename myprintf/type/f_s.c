#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.length != 0 && opts.length != 11)
	{
		pf_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static char	*padding(char *s, int size, int len, int left_align)
{
	char	*str;

	if (!(str = (char*)pf_memalloc(size + 1)))
		return (NULL);
	pf_memset(str, ' ', size);
	str[size] = '\0';
	if (left_align)
		pf_strncpy(str, s, len);
	else
		pf_strncpy(&str[size - len], s, len);
	free(s);
	return (str);
}

int			d_s(t_opts opts, va_list ap)
{
	char	*s;
	int		len;

	if (opts.length == 11)
	{
		opts.length = 0;
		return (f_us(opts, ap));
	}
	error_check(opts);
	if (!(s = va_arg(ap, char *)))
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = pf_strlen(s);
	if (opts.precision >= 0)
		len = MIN(len, opts.precision);
	s = pf_strndup(s, len);
	if (opts.width > len)
		s = padding(s, opts.width, len, opts.flags.minus);
	pf_putstr(s);
	len = pf_strlen(s);
	free(s);
	return (len);
}
