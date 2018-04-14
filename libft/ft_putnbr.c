#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	num;

	num = (nb < 0) ? -nb : nb;
	if (nb < 0)
		ft_putchar('-');
	if (num >= 10)
		ft_putnbr(num / 10);
	(num >= 10) ? ft_putchar(num % 10 + '0') : ft_putchar(num + '0');
}
