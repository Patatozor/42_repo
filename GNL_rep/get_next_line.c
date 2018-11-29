/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:41:56 by rfumeron          #+#    #+#             */
/*   Updated: 2018/11/29 17:58:47 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_fd_file(t_list **files, int fd)
{
	t_list	*tmp;
	t_file	f;

	tmp = *files;
	while (tmp)
	{
		if (((t_file *)((tmp->content)))->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	f.fd = fd;
	f.cont = ft_strnew(0);
	f.temp = f.cont;
	ft_lstadd((files), ft_lstnew((void *)&f, sizeof(t_file)));
	return (*files);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*file;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	file = get_fd_file(&file, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(CONT(file) = ft_strjoin(CONT(file), buff)))
			return (-1);
		ft_strdel(&(TEMP(file));
		TEMP(file) = CONT(file);
		if (ft_strchr(CONT(file), CHAR_STOP))
			break ;
	}
//	if (PRINT == 1)
//		ft_putendl(*line);
	if (ret < BUFF_SIZE && !ft_strlen(CONT(file)))
		return (0);
	return (1);
}
