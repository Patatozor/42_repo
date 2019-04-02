/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:05:00 by rfumeron          #+#    #+#             */
/*   Updated: 2019/04/02 17:05:34 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "tools.h"

# define SPEC_COUNT 12

typedef struct		s_flag
{
	int				pound;
	int				zero;
	int				minus;
	int				plus;
	int				space;
}					t_flags;

typedef struct		s_opts
{
	t_flags			flags;
	int				width;
	int				precision;
	int				length;
}					t_opts;

int					f_c(t_opts opts, va_list ap);
int					f_s(t_opts opts, va_list ap);
int					f_p(t_opts opts, va_list ap);
int					f_d(t_opts opts, va_list ap);
int					f_o(t_opts opts, va_list ap);
int					f_u(t_opts opts, va_list ap);
int					f_x(t_opts opts, va_list ap);
int					f_ux(t_opts opts, va_list ap);
int					f_f(t_opts opts, va_list ap);
int					f_b(t_opts opts, va_list ap);
int					f_percent(t_opts opts, va_list ap);

typedef int			(*t_spec) (t_opts, va_list);
typedef struct		s_dispatch
{
	char			op;
	t_spec			s;
}					t_dispatch;

const t_dispatch	g_select[] = {
	{'c', &f_c},
	{'s', &f_s},
	{'p', &f_p},
	{'d', &f_d},
	{'i', &f_d},
	{'o', &f_o},
	{'u', &f_u},
	{'x', &f_x},
	{'X', &f_ux},
	{'f', &f_f},
	{'b', &f_b},
	{'%', &f_percent}
};

int					ft_printf(char *str, ...);
t_opts				get_opts(char **str, va_list ap);

#endif
