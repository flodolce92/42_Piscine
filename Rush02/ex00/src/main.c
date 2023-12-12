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

int	new_element(t_dict **headDict, int nb, char *literal)
{
	t_dict	*new;

	new = (t_dict *) malloc(sizeof(t_dict));
	new->nb = nb;
	new->literal = ft_strdup(literal);
	new->next = NULL;
	if (headDict)
	{
		new->next = *headDict;
		*headDict = new;
	}
	else
	{
		*headDict = new;
	}
	return (1);
}

int	get_nb(int *nb, char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *) malloc(sizeof(char));
	temp[0] = '\0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = add_char(temp, str[i]);
		i++;
	}
	*nb = ft_atoi(temp);
	return (1);
}

int	get_val(char **literal, char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 'a' && str[i] <= 'z')
	{
		*literal = add_char(*literal, str[i]);
		i++;
	}
	return (1);
}

int	parse_dict(t_dict **headDict, char *str)
{
	int		nb;
	char	*literal;

	literal = (char *) malloc(sizeof(char));
	literal[0] = '\0';
	if (!get_nb(&nb, str))
		return (0);
	if (!get_val(&literal, str))
		return (0);
	new_element(headDict, nb, literal);
	printf("This %p : Num %d : Lit %s : Next %p\n", (*headDict), (*headDict)->nb, (*headDict)->literal, (*headDict)->next);
	return (1);
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

	dict = NULL;
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
