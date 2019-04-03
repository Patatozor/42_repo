#include "../inc/ft_printf.h"

char	*pf_itoa_abs(int64_t n)
{
	char	*str;
	int		sign;
	int		len;

	sign = (n >= 0 ? 1 : -1);
	len = pf_placevalue(n);
	if (!(str = (char *)pf_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len--;
	while (n)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
		len--;
	}
	return (str);
}
