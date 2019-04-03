#include "../inc/ft_printf.h"

void	pf_putwstr(wchar_t *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}
