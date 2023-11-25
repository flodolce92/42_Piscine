/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:26:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/10/05 19:29:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;
	char	*temp;

	i = 1;
	start = 1;
	end = argc - 1;
	while (start < end)
	{
		temp = argv[start];
		argv[start] = argv[end];
		argv[end] = temp;
		start++;
		end--;
	}
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
