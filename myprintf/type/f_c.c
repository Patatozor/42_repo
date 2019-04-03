#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.length != 0 && opts.length != 11)
	{
		pf_putstr("error: undefined behavior");
		exit(1);
	}
}

static void	pt_putspaces(int size)
{
	int		i;

	i = 0;
	while (i++ < size)
		pf_putchar(' ');
}

static void	padding(char c, int size, int left_align)
{
	if (!left_align && size)
		pf_putspaces(size - 1);
	pf_putchar(c);
	if (left_align && size)
		pf_putspaces(size - 1);
}

int			f_c(t_opts opts, va_list ap)
{
	char	c;

	if (opts.length == 11)
	{
		opts.length = 0;
		return (f_uc(opts, ap));
	}
	error_check(opts);
	c = va_arg(ap, int);
	padding(c, opts.width, opts.flags.minus);
	return (opts.width > 1 ? opts.width : 1);
}
