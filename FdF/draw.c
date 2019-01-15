/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:41:54 by rfumeron          #+#    #+#             */
/*   Updated: 2019/01/15 12:07:22 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	draw(char ***str)
{
	void	*mlx_ptr;
	void	*mlx_window;
	int		x;
	int		y;

	x = 0;
	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 1400, 1000, "FdF");
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			mlx_pixel_put(mlx_ptr, mlx_window, 200 + (V2S2 * (x - y)) * SPACING,
					200 + (V2S3 * ft_atoi(str[x][y]) - USV6 * (x + y)) * SPACING,
					255255);
			y++;
		}
		x++;
	}
	mlx_loop(mlx_ptr);
}
