/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 02:00:28 by rfumeron          #+#    #+#             */
/*   Updated: 2018/10/22 02:03:23 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*ret;
	int		fd;

	fd = open("test", O_RDONLY);
	get_next_line(fd, &ret);
	ft_putstr(ret);
	get_next_line(fd, &ret);
	ft_putstr(ret);
	get_next_line(fd, &ret);
	ft_putstr(ret);
	close(fd);
}
