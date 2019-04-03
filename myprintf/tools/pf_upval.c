#include "../inc/ft_printf.h"

int		pf_upval(uint64_t n)
{
	int count;
	
	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
