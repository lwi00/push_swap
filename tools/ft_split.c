/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:51 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 16:02:21 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_in_charset(char c, char charset)
{
	return (c == charset);
}

static size_t	count_words(const char *str, char charset)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			count++;
			while (*str && !is_in_charset(*str, charset))
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*extract_word(const char **str, char charset)
{
	const char	*start = *str;
	size_t		len;

	len = 0;
	while (**str && !is_in_charset(**str, charset))
	{
		(*str)++;
		len++;
	}
	return (ft_substr(start, 0, len));
}

static void	free_split(char **ret, size_t idx)
{
	while (idx > 0)
		free(ret[--idx]);
	free(ret);
}

char	**ft_split(char const *str, char charset)
{
	char	**ret;
	size_t	words;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	words = count_words(str, charset);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			ret[i] = extract_word(&str, charset);
			if (!ret[i++])
				return (free_split(ret, i - 1), NULL);
		}
		else
			str++;
	}
	ret[i] = NULL;
	return (ret);
}
