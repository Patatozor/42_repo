#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if (d >= 'a' && d <= 'z')
		return ((int)(d - 32));
	return (c);
}
