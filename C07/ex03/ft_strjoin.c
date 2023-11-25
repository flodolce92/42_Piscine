/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:22:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/10/10 09:00:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_size(int size, char **strs, char *sep)
{
	int	i;
	int	tot_len;

	tot_len = 0;
	i = 0;
	while (i < size)
	{
		tot_len += ft_strlen(strs[i]);
		if (i < size - 1)
			tot_len += ft_strlen(sep);
		i++;
	}
	return (tot_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	s = (char *) malloc(check_size(size, strs, sep) + 1);
	if (size == 0)
		return (s);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			s[k++] = sep[j++];
		i++;
	}
	s[k] = '\0';
	return (s);
}
