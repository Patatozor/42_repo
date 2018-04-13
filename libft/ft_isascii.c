#include "libft.h"

int	ft_isascii(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (d >= 0 && d <= 127)
		return (1);
	return (0);
}
