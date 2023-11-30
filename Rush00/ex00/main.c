/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:46:47 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/09/23 16:35:30 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("Invalid number of arguments.\n");
		return (1);
	}
	rush(ft_atoi(av[1]), ft_atoi(av[2]));
	return (0);
}
