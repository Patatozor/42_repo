#include "../inc/ft_printf.h"

size_t		pf_wcslen(wchar_t *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
