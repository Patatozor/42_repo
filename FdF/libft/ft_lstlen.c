/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:16:48 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/12 14:05:52 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list **alst)
{
	t_list	*list;
	int		len;

	list = *alst;
	len = 0;
	if (!list)
		return (len);
	while (list->next)
	{
		len++;
		list = list->next;
	}
	return (len + 1);
}
