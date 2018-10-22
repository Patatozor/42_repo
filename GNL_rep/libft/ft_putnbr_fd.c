/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:02:58 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/17 16:29:49 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	(nb >= 10) ? ft_putchar_fd(nb % 10 + '0', fd) : ft_putchar_fd(nb + '0', fd);
}
