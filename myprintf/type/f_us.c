#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.length != 0)
	{
		pf_putstr("error: undefined behavior\n");
		exit(1);
	}
}

static void	pf_putspaces(int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		pf_putchar(' ');
}

static void	padding(wchar_t *s, int size, int len, int left_align)
{
	if (!left_align && size > len)
		pf_putspaces(size - len);
	pf_putwstr(s);
	if (left_align && size > len)
		pf_putspaces(size - len);
}

int			f_us(t_opts opts, va_list ap)
{
	wchar_t		*w;
	int			len;

	error_check(opts);
	if (!(w = va_arg(ap, wchar_t*)))
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = pt_wcslen(w);
	if (opts.precision >= 0)
		len = MIN(len, opts.precision);
	padding(w, opts.width, len, opts.flags.minus);
	len = MAX(len, opts.width);
	return (len);
}
