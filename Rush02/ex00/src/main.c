/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:28:24 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/08 02:40:48 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	manage_argvs(int ac, char **av, char **dictpath, char **nb)
{
	if (ac == 2)
	{
		*dictpath = "./numbers.dict";
		*nb = av[1];
		return (1);
	}
	else if (ac == 3)
	{
		*dictpath = av[1];
		*nb = av[2];
		return (1);
	}
	return (0);
}

void	find_nb(char *dictpath, char *nb)
{
}

int	main(int ac, char **av)
{
	char	*dictpath;
	char	*nb;

	if (ac > 3)
		ft_putstr("Too many arguments.\n");
	else if (ac == 1)
		ft_putstr("Too few arguments.\n");
	else
	{
		manage_argvs(ac, av, &dictpath, &nb);
		if (ft_atoi(nb) != 0)
		{
			ft_putstr("Prova ad aprire file\n");
			open_file(dictpath);
			ft_putstr("Trova Numero\n");
			find_nb(dictpath, nb);
		}
		else
			ft_putstr("Error\n");
	}
	return (0);
}
