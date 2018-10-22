/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:02:31 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/17 15:02:33 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
