/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 01:51:43 by rfumeron          #+#    #+#             */
/*   Updated: 2018/11/29 17:58:44 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 32
# define PRINT 0
# define SKIP_BLANK 0
# define CHAR_STOP '\n'
# define CONT(x) ((t_file *)((x->content)))->cont
# define TEMP(x) ((t_file *)((x->content)))->temp

typedef struct	s_file
{
	int			fd;
	char		*cont;
	char		*temp;
}				t_file;

int			get_next_line(const int fd, char **line);
#endif
