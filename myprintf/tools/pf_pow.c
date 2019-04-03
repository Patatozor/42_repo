#include "../inc/ft_printf.h"

double		pow(double n, int precision)
{
	double	res;

	res = n;
	while (precision > 1)
	{
		res = res * n;
		precision--;
	}
	return (res);
}
