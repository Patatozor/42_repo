#include "../inc/ft_printf.h"

char	*pf_uitoa(uint64_t n)
{
	char	*str;
	int		len;

	len = pf_upval(n);
	if (!(str = (char *)pf_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len--;
	while (n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
