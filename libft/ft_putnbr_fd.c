#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;

	n = (nb < 0) ? -nb : nb;
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (n >= 10)
		ft_putnbr(n / 10);
	(n >= 10) ? ft_putchar(n % 10 + '0', fd) : ft_putchar(n + '0', fd);
}
