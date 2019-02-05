/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:15:56 by rfumeron          #+#    #+#             */
/*   Updated: 2019/02/05 10:39:26 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file_name(char *s)
{
	while(*s)
		s++;
	if (ft_strequ(s - 4, ".fdf"))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	***points;
//	int		x;
//	int		y;

	if (ac != 2 || !check_file_name(av[1]))
	{
		ft_putendl("incorrect or no map given to fdf");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (!(points = fdf_parse(fd)))
	{
		ft_putendl("incorrect map characters");
		return (-1);
	}
	draw(points);
//	x = 0;
//	while (points[x])
//	{
//		y = 0;
//		while (points[x][y])
//		{
//			ft_putstr("x: :");
//			ft_putnbr((float)x * 82);
//			ft_putstr("  y: ");
//			ft_putnbr((float)y * 82);
//			ft_putstr("  z: ");
//			ft_putnbr_endl((float)(ft_atoi(points[x][y++])) * 82);
//		}
//		x++;
//	}
	return (0);
}
