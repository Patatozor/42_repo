#include "libft.h"

int	ft_isalpha(int c)
{
	char	d;

	d = (char)c;
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}
