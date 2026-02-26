/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:08:13 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:58:12 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**free_split(char **split, int j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static int	fill_split(char **split, const char **s, char c)
{
	int	j;

	j = 0;
	while (**s)
	{
		if (**s != c)
		{
			split[j] = ft_substr(*s, 0, word_length(*s, c));
			if (!split[j])
				return (-1);
			j++;
			while (**s && **s != c)
				(*s)++;
		}
		else
			(*s)++;
	}
	split[j] = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (fill_split(split, &s, c) == -1)
		return (free_split(split, word_count));
	return (split);
}
