/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfumeron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:09:09 by rfumeron          #+#    #+#             */
/*   Updated: 2018/04/24 18:19:18 by rfumeron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

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

static int	count_chars(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		chars;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	str = ft_strrev(ft_strtrimchar(s, c));
	tab[words] = 0;
	chars = count_chars(str, c);
	while (words--)
	{
		chars = count_chars(str, c);
		if (!(tab[words] = malloc(sizeof(char) * (chars + 1))))
			return (NULL);
		tab[words][chars] = '\0';
		while (chars--)
			tab[words][chars] = *str++;
		while (*str && *str == c)
			str++;
	}
	return (tab);
}
