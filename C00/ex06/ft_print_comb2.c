/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:29:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/09/23 23:04:35 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_split(int a, int b)
{
	char	c;

	c = 48 + a / 10;
	write(1, &c, 1);
	c = 48 + a % 10;
	write(1, &c, 1);
	write(1, &" ", 1);
	c = 48 + b / 10;
	write(1, &c, 1);
	c = 48 + b % 10;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			write_split(a, b);
			if (!(a == 98 && b == 99))
				write(1, &", ", 2);
			b++;
		}
		a++;
	}
}
