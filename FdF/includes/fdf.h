/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:48:46 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/07 18:36:38 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

typedef	struct	s_coord
{
	int			x;
	int			y;
	int			h;
}				t_coord;

t_list			**fdf_parse(int fd);
t_coord			fdf_coordnew(int x, int y, int h);
#endif
