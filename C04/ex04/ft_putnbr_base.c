/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:13:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/06 06:27:56 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
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

void	print_nbr(long long nb, char *base, int nbase)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		print_nbr(nb, base, nbase);
	}
	else if (nb > nbase - 1)
	{
		print_nbr(nb / nbase, base, nbase);
		print_nbr(nb % nbase, base, nbase);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nb, char *base)
{
	int			nbase;
	long long	long_nb;

	long_nb = nb;
	nbase = check_base(base);
	if (nbase)
		print_nbr(long_nb, base, nbase);
}
