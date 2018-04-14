#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	int	i;
	char	*s3;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	s3 = malloc(sizeof(char) * (s1len + s2len + 1));
	s3 = ft_strcat(s1, s2);
	return (s3);
}