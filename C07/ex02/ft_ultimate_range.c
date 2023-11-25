/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:51:13 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/10/05 22:13:37 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	tot_int;
	int	*arr;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tot_int = max - min;
	arr = (int *)malloc(sizeof(int) * tot_int);
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (i);
}
