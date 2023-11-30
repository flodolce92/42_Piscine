/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:49:44 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/09/23 16:34:43 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// prototipazione funzione putchar
void	ft_putchar(char c);

void	ft_putstr(char *str);

// controllo e stampa
void	print_char(int a, int b, int x, int y)
{
	if ((a == 0 && b == 0) || (a == x - 1 && b == y - 1))
		ft_putchar('A');
	else if ((a == 0 && b == y - 1) || (a == x - 1 && b == 0))
		ft_putchar('C');
	else if ((a == 0 || a == x - 1) || (b == 0 || b == y - 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

// creazione griglia
void	rush(int x, int y)
{
	int	a;
	int	b;

	if (x <= 0 || y <= 0)
	{
		ft_putstr("Invalid number.\n");
		ft_putstr("Please insert only positive numbers in the int range.\n");
		return ;
	}
	b = 0;
	while (b < y)
	{
		a = 0;
		while (a < x)
		{
			print_char(a, b, x, y);
			a++;
		}
		b++;
		ft_putchar('\n');
	}
}
