#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (d >= 'A' && d <= 'Z')
		return ((int)(d + 32));
	return (c);
}
