/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 01:51:43 by rfumeron          #+#    #+#             */
/*   Updated: 2018/11/13 18:38:25 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 32
# define PRINT 0
# define SKP_BLK 0
# define CHAR_STOP '\n'

int		get_next_line(const int fd, char **line);
#endif
