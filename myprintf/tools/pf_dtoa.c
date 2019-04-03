#include "../inc/ft_printf.h"

char	*pf_dtoa(long double n, int precision)
{
	char	*s;
	long	tmp;
	long	t;
	int		len;

	if (!precision)
		return (pf_itoa((int64_t)n));
	tmp = (n * pf_pow(10, precision));
	t = (tmp < 0) ? -tmp : tmp
		len = (n <= 0 ? 3 : 2);
	while (tmp && ++len)
		tmp /= 10;
	if (!(s = pf_strnew(len + 1)))
		return (NULL);
	s[--len] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (t)
	{
		s[--len] = (!precision--) ? '.' : t % 10 + '0';
		t /= (precision + 1) ? 10 : 1;
	}
	return (s);
}
