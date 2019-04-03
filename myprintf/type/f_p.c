#include "../inc/ft_printf.h"

static void	error_check(t_opts opts)
{
	if (opts.length != 0)
	{
		pt_putstr("error: undefined behavior");
		exit(1);
	}
}

static char	*convert(uint64_t p)
{
	int		i;
	char	*s;
	char	*hex;

	if (!(s = (char *)pf_strnew(14)))
		return (NULL);
	hex = "0123456789abcdef";
	s[0] = '0';
	s[1] = 'x';
	i = 2;
	if (!p)
		s[2] = '0';
	while (p)
	{
		s[i] = hex[p & 15];
		p >>= 4;
		i++;
	}
	pf_strrev(&s[2]);
	return (s);
}

static char	*padding(char *s, t_opts opts)
{
	char	*str;

	if (!(str = (char *)pt_strnew(opts.width)))
		return (NULL);
	pf_memset(str, ' ', opts.width);
	if (opts.flags.minus)
		pf_strncpy(str, s, 14);
	else
		pf_strncpy(&str[opts.width - 14], s, 14);
	free(s);
	return (str);
}

int			f_p(t_opts opts, va_list ap)
{
	uint64_t	p;
	char		*s;
	int			len;

	error_check(opts);
	p = va_arg(ap, uint64_t);
	s = convert(p);
	len = 14;
	if (opts.width > 14)
		s = padding(s, opts);
	pf_putstr(s);
	free(s);
	return (pf_strlen(s));
}
