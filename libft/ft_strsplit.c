/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:02:13 by laskolin          #+#    #+#             */
/*   Updated: 2019/11/06 10:51:45 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static int	word_len(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		a;

	if (!s)
		return (NULL);
	fresh = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!fresh)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			fresh[a] = ft_strsub(s, i, word_len(s, c, i));
			a++;
		}
		i++;
	}
	fresh[a] = NULL;
	return (fresh);
}
