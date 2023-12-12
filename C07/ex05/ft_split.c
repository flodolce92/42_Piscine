/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:07:21 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/12 00:22:58 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_inset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_inset(str[i], charset) == 0
			&& is_inset(str[i + 1] == 1, charset))
			count++;
		i++;
	}
	return (count);
}

void	fill_word(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	fill_split(char **split, char *str, char *charset)
{
	int	word;
	int	i;
	int	len;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_inset(str[i], charset) == 1)
			i++;
		else
		{
			len = 1;
			while (is_inset(str[i + len], charset) == 0)
				len++;
			split[word] = (char *) malloc(sizeof(char) * (len + 1));
			fill_word(split[word], &str[i], len);
			i += len;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	words = count_words(str, charset);
	split = (char **) malloc(sizeof(char *) * (words + 1));
	split[words] = NULL;
	fill_split(split, str, charset);
	return (split);
}
