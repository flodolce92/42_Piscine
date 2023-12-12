/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:10:31 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/12 22:10:34 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	convert_nbr(long long nb, char *base, int nbase, char **nbr_converted);
int		is_valid_nbr(char c);
int		ft_strlen(char *str);

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c + 32);
	return (c);
}

int	get_nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (to_lower(c) == to_lower(base[i]))
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base, int nbase)
{
	int	i;
	int	neg;
	int	res;

	neg = 1;
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (is_valid_nbr(str[i]))
	{
		res = res * nbase + get_nbr(str[i], base);
		i++;
	}
	return (res * neg);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			nbase_from;
	int			nbase_to;
	long long	long_nb;
	char		*nbr_converted;

	nbr_converted = (char *) malloc(sizeof(char));
	nbr_converted[0] = '\0';
	nbase_from = check_base(base_from);
	nbase_to = check_base(base_to);
	if (nbase_from && nbase_to)
	{
		long_nb = ft_atoi_base(nbr, base_from, nbase_from);
		convert_nbr(long_nb, base_to, nbase_to, &nbr_converted);
	}
	return (nbr_converted);
}
