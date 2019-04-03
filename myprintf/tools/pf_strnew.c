#include "../inc/ft_printf.h"

char	*pf_strnew(size_t size)
{
	char	*temp;

	if (!(temp = (char *)malloc(size + 1)))
		return (NULL);
	temp = pf_memset(temp, '\0', size + 1);
	return (temp);
}
