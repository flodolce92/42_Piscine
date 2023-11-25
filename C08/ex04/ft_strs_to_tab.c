/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:41:40 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/10/11 16:51:38 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		srclen;

	srclen = ft_strlen(src);
	dup = (char *) malloc(sizeof(char) * srclen + 1);
	return (ft_strcpy(dup, src));
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_arr;
	int			i;

	i = 0;
	s_arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s_arr)
		return (NULL);
	while (i < ac)
	{
		s_arr[i].str = av[i];
		s_arr[i].size = ft_strlen(av[i]);
		s_arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_arr[i].str = 0;
	return (s_arr);
}
