#include "../inc/ft_printf.h"

void	pf_putwchar(wchar_t c)
{
	write(1, &c, 1);
}
