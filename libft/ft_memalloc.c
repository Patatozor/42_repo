#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size_t size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
