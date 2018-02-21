/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:32:04 by rfumeron          #+#    #+#             */
/*   Updated: 2018/02/20 15:30:22 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_char_rank(char c, char *base)
{
	int i;
	
	i = 0;
	while (base[i] && c != base[i])
		i++;
	return (i);
}

int		ft_check_str(char *str, char *base)
{
	int i;
	int j;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] != base[j] && str[i])
			j++;
		if (str[i] == base[j])
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	neg = 1;
	if ((str[i] == '-' || str[i] == '+')
		&& str[i + 1] != '+' && str[i + 1] != '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	if (ft_check_base(base) && ft_check_str(str, base))
	{
		while (str[i] != '\0')
		{
			nb *= ft_check_base(base);
			nb += ft_get_char_rank(str[i], base);
			i++;
		}
	}
	return (nb * neg);
}
