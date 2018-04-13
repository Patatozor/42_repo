#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (d >= 40 && d <= 126)
		return (1);
	return (0);
}
