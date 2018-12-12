/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:46:09 by rfumeron          #+#    #+#             */
/*   Updated: 2018/12/12 16:19:05 by rfumeron         ###   ########.fr       */
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

int			machin(char **dst, char const *src, char c)
{
	if ((*dst = ft_strcpyuntilc(*dst, src, c)))
		return (ft_strlenuntilc(src, c));
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	char	*temp;
	int 	words;
	int		i;

	i = 0;
	if (s == NULL || ((words = count_words(s, c)) == 0) ||
				!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	str = ft_strtrimchar(s, c);
	temp = str;
	while (i < words)
	{
		str += machin(&(tab[i]), s, c) + 1;
		i++;
	}
	tab[i] = NULL;
	free(temp);
	return (tab);
}
