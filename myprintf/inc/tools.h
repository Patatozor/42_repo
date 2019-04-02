/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:03:08 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 17:05:42 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>

void		pf_putchar(char c);
void		pf_putstr(char const *s);
void		*pf_memalloc(size_t size);
void		pf_bzero(void *str, size_t n);
void		pf_memset(void *b, int c, size_t len);
void		pf_memcpy(void *dst, const void *src, size_t n);
size_t		pf_strlen(char const *s);
int			pf_atoi(char const *s);
int			pf_isspace(char c);
int			pf_placevalue(int n);
char		*pf_strndup(const char *src, size_t len);
char		*pf_strncpy(char *dst, const char *src, size_t len);
char		*pf_strnew(size_t size);
char		*pf_strrev(char *str);
char		*pf_itoa(int n);
char		*pf_itoh(int n, int caps);
char		*pf_itoo(int n);
char		*pf_dtoa(double n, int precision);

#endif
