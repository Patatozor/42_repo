/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:15:56 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/12 15:33:55 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	t_list	**points;
	t_list	*p;
	t_coord	*c;

	if (ac != 2)
	{
		ft_putendl("no map given to fdf");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	points = fdf_parse(fd);
	p = *points;
	while (p->next)
	{
		c = ((t_coord *)((p->content)));
		printf("x: %d y: %d h: %d \n", c->x, c->y, c->h);
		p = p->next;
	}
	while (1 == 1)
		;
	return (0);
}
