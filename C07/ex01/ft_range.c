/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:16:50 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/10/05 21:37:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	tot_int;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	tot_int = max - min;
	arr = (int *)malloc(sizeof(int) * tot_int);
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
