/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:46:17 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/21 19:16:10 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s[i] && s[i] != c)
		words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

int			get_index_of_c_and_move(char **dst, char const *src, char c)
{
	int		i;

	i = ft_strlenuntilc(src, c);
	if (!(*dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	if ((*dst = ft_strncpy(*dst, src, i)))
		return (i);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	char	*temp;
	int		words;
	int		i;

	i = 0;
	if (s == NULL || ((words = count_words(s, c)) == 0) ||
				!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	str = ft_strtrimchar(s, c);
	temp = str;
	while (i < words)
	{
		str += get_index_of_c_and_move(&(tab[i]), str, c) + 1;
		i++;
	}
	tab[i] = NULL;
	free(temp);
	return (tab);
}
