/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:12:02 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/06 14:12:32 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_fd_file(t_list **files, int fd)
{
	t_list			*tmp;
	t_file			f;

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

char			*get_line(char **content)
{
	char			*line;
	size_t			len;

	if (ft_strchr(*content, CHAR_STOP))
	{
		len = ft_strchr(*content, CHAR_STOP) - *content;
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += len;
		if (SKIP_BLANK == 1)
		{
			while (**content == CHAR_STOP)
				*content += 1;
		}
		else
			*content += 1;
	}
	else
	{
		len = ft_strlen(*content);
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += len;
	}
	return (line);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*file;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	file = get_fd_file(&files, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(CONT(file) = ft_strjoin(CONT(file), buff)))
			return (-1);
		ft_strdel(&(TEMP(file)));
		TEMP(file) = CONT(file);
		if (ft_strchr(CONT(file), CHAR_STOP))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(CONT(file)))
		return (0);
	if (!(*line = get_line(&CONT(file))))
		return (-1);
	return (1);
}
