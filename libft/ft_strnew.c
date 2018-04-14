#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	if (!(newstr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(newstr, (int)'\0', size + 1);
	return (newstr);
}
