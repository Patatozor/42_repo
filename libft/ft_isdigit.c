#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}
