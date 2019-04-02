/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:15:08 by rfumeron          #+#    #+#             */
/*   Updated: 2019/01/15 12:07:38 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_file_to_list(int fd, t_list ***alst)
{
	t_list	*list;
	char	*line;

	if (ft_get_next_line(fd, &line) == 1)
	{
		list = ft_lstnewstr(line, ft_strlen(line));
		((char *)((list->content)))[ft_strlen(line)] = '\0';
		*alst = &list;
		ft_strdel(&line);
		while (ft_get_next_line(fd, &line) == 1)
		{
			ft_lstaddback(*alst, ft_lstnewstr(line, ft_strlen(line)));
			ft_strdel(&line);
		}
	}
}

char	***get_str_from_file(int fd)
{
	t_list	**alst;
	t_list	*list;
	char	***str;
	int		i;

	alst = NULL;
	fdf_file_to_list(fd, &alst);
	list = *alst;
	alst = &list;
	i = 0;
	if (!(str = malloc(sizeof(char **) * (ft_lstlen(&list) + 1))))
		return (NULL);
	while (list->next)
	{
		str[i++] = ft_strsplit(list->content, ' ');
		ft_strdel((char **)(&(list->content)));
		free(list);
		list = list->next;
	}
	str[i++] = ft_strsplit(list->content, ' ');
	ft_strdel((char **)(&(list->content)));
	free(list);
	str[i] = NULL;
	return (str);
}

int		check_points(char ***str)
{
	int			x;
	int			y;

	x = 0;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (ft_isnumber(str[x][y]))
				y++;
			else
				return (0);
		}
		x++;
	}
	return (1);
}

char	***fdf_parse(int fd)
{
	char		***str;

	str = get_str_from_file(fd);
	if (check_points(str))
		return (str);
	else
		return (NULL);
}
