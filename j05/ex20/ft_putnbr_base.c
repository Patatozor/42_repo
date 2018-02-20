/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:30 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/20 14:38:11 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		base_is_correct(char *base)
{
	int base_len;
	int j;
	int	base_is_correct;

	base_len = 0;
	base_is_correct = 1;
	while (base[base_len] != '\0' && base_is_correct == 1)
	{
		j = 0;
		while (j < base_len)
		{
			if (base[base_len] == base[j] || base[base_len] == '-'
					|| base[base_len] == '+')
				base_is_correct = 0;
			j++;
		}
		base_len++;
	}
	if (base_len <= 1 || base_is_correct == 0)
		return (0);
	else
		return (base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = base_is_correct(base);
	if (base_len)
	{
		if (nbr == -2147483648)
		{
			i = 1;
			nbr = nbr + i;
		}
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= base_len)
		{
			ft_putnbr_base(nbr / base_len, base);
			ft_putchar(base[nbr % base_len] + i);
		}
		else
			ft_putchar(base[nbr]);
	}
}
