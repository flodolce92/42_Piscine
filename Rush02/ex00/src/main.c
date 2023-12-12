/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:28:24 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/11 03:28:24 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	parse_dict(t_dict **headDict, char *str)
{
}

char	*add_char(char *str, char buf)
{
	char	*temp;
	int		strlen;
	int		i;

	i = 0;
	strlen = ft_strlen(str);
	temp = (char *) malloc(sizeof(char) * strlen + 2);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = buf;
	temp[i + 1] = '\0';
	free(str);
	return (temp);
}

int	read_file(int fd, t_dict **headDict)
{
	char	buf[1];
	char	*str;

	str = (char *) malloc(sizeof(char));
	str[0] = '\0';
	while (read(fd, buf, 1) != 0)
	{
		if (buf[0] != '\n')
		{
			str = add_char(str, buf[0]);
		}
		else
		{
			//ft_putstr("RIGA ");
			//ft_putstr(str);
			//ft_putstr("\n");
			parse_dict(headDict, str);
			free(str);
			str = (char *) malloc(sizeof(char));
			str[0] = '\0';
		}
	}
	return (1);
}

int	open_file(char	*dictpath, t_dict **headDict)
{
	int	fd;

	fd = open(dictpath, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read_file(fd, headDict))
		return (1);
	return (0);
}

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

int	main(int ac, char **av)
{
	t_dict	*dict;
	char	*dictpath;
	char	*nb;

	if (ac > 3)
		ft_putstr("Too many arguments.\n");
	else if (ac == 1)
		ft_putstr("Too few arguments.\n");
	else
	{
		manage_argvs(ac, av, &dictpath, &nb);
		if (ft_str_is_numeric(nb) != 0)
		{
			ft_putstr("Prova ad aprire file\n");
			if (!open_file(dictpath, &dict))
				return (-1);
		}
		else
			ft_putstr("Error\n");
	}
	free(dict);
	return (0);
}
