/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:41:56 by rfumeron          #+#    #+#             */
/*   Updated: 2018/11/13 18:40:02 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char			*cut_untilc(char *dst, t_list *src, char c)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = ft_strlenuntilc(src->content, c);
	j = ft_strlen(src->content);
	if (!(dst = malloc(sizeof(char) * i + 1))
			|| !(temp = malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	if (i == 0)
	{
		dst[0] = '\0';
		src->content += 2;
	}
	else
	{
		dst = ft_strcpyuntilc(dst, src->content, c);
		temp = ft_strcpy(temp, src->content + i);
		if (SKP_BLK == 1)
		{
			while (*temp == c)
				temp++;
		}
		else
		{
			if (*temp == c)
				temp += 1;
		}
		src->content = temp;
	}
	return (dst);
}

void			print_and_close(char *str)
{
	if (str && PRINT == 1)
		ft_putendl(str);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*fd_file;
	char			*buff;
	int				ret;

	if (!(buff = malloc(sizeof(char) * (BUFF_SIZE + 1))) ||
			fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	fd_file = get_fd_file(&file, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(fd_file->content = ft_strjoin(fd_file->content, buff)))
			return (-1);
		if (ft_strchr(buff, CHAR_STOP))
			break ;
	}
	*line = cut_untilc(*line, fd_file, CHAR_STOP);
	if (!ft_strlen(fd_file->content) && ret == 0)
			return (0);
	print_and_close(*line);
	return (1);
}
