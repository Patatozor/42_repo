/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:41:56 by rfumeron          #+#    #+#             */
/*   Updated: 2018/10/22 02:00:01 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_print_lst(t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		ft_putnbr(tmp->content_size);
		ft_putchar('\n');
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

static t_list	*get_fd_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*fd_file;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	fd_file = get_fd_file(&file, fd);
	*line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(fd_file->content = ft_strjoin(fd_file->content, buff)))
			return (-1);
		if (ft_strchr(buff, CHAR_STOP))
			break ;
	}
	*line = ft_strcpyuntilc(*line, fd_file->content, CHAR_STOP);
	free(fd_file->content);
	return (1);
}
