/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:40:00 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/13 01:27:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_valid_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	res;
	int	nbase;

	nbase = check_base(base);
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
