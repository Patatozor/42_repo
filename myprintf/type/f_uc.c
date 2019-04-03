#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.length != 0)
	{
		pf_putstr("error: undefined behavior");
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

static void	padding(char c, int size, int left_align)
{
	if (!left_align && size)
		pf_putspaces(size - 1);
	pf_putwchar(c);
	if (left_align && size)
		pf_putspaces(size - 1);
	return ;
}

int			f_uc(t_opts opts, va_list ap)
{
	wchar_t	c;

	error_check(opts);
	c = va_arg(ap, wchar_t);
	padding(c, opts.width, opts.flags.minus);
	return (opts.width > 1 ? opts.width : 1);
}
