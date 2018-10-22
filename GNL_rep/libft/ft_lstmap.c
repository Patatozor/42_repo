/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:38:20 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/26 06:18:07 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*list;

	if (!lst || !f)
		return (NULL);
	if (!(list = f(lst)))
	{
		free(list);
		return (NULL);
	}
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list = f(lst)))
		{
			free(list);
			return (NULL);
		}
		ft_lstaddback(&new, list);
	}
	return (new);
}
