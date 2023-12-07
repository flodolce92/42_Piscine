/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:44:51 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/07 15:07:23 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_arr(int *arr, int len, int n)
{
	int	j;

	j = 0;
	while (j <= len)
	{
		ft_putchar(arr[j] + 48);
		j++;
	}
	if (arr[0] != 10 - n - len)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	recursive_print(int *arr, int len, int n)
{
	int	i;

	i = 0;
	if (len != 0)
		i = arr[len - 1] + 1;
	while (i <= 10 - n)
	{
		arr[len] = i;
		if (n != 1)
			recursive_print(arr, len + 1, n - 1);
		else
		{
			print_arr(arr, len, n);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	recursive_print(arr, 0, n);
}
