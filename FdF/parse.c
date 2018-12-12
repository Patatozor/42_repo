/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:15:08 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/12 15:33:43 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_file_to_list(int fd, t_list ***alst)
{
	t_list	*list;
	char	*line;

	if (ft_get_next_line(fd, &line) > 0)
	{
		list = ft_lstnewstr(line, ft_strlen(line));
		((char *)((list->content)))[ft_strlen(line)] = '\0';
		*alst = &list;
		ft_strdel(&line);
		while (ft_get_next_line(fd, &line) > 0)
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
	ft_lstdel(alst, &ft_bzero);
	ft_strdel((char **)(&(list->content)));
	str[i] = NULL;
	return (str);
}

t_list	**convert_str_to_coord(char ***str)
{
	t_list	*list;
	t_list	**alst;
	t_coord	p;
	int		x;
	int		y;

	x = 0;
	list = ft_lstnew(NULL, 0);
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			p = fdf_coordnew(x, y, ft_atoi(str[x][y]));
			ft_lstaddback(&list, ft_lstnew(&p, sizeof(t_coord)));
			free((str[x][y++]));
		}
		free(str[x]);
		str[x++] = NULL;
	}
	free(str);
	ft_lstaddback(&list, ft_lstnew(NULL, 0));
	alst = &(list->next);
	ft_strdel((char **)(&(list->content)));
	return (alst);
}

t_list	**fdf_parse(int fd)
{
	t_list		**points;
	char		***str;

	str = get_str_from_file(fd);
	points = convert_str_to_coord(str);
	return (points);
}
