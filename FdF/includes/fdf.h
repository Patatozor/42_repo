/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:48:46 by rfumeron          #+#    #+#             */
/*   Updated: 2019/01/15 11:59:55 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1000
# define HEIGHT 1000
# define V2S2 0.7071f
# define V2S3 0.4714f
# define USV6 0.4082f
# define SPACING 10
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>

char				***fdf_parse(int fd);
void				draw(char ***str);
#endif
