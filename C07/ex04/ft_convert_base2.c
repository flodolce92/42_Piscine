/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:10:38 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/12 22:10:42 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	is_valid_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

void	add_char(char **nbr_converted, char c)
{
	int		strlen;
	int		i;
	char	*temp;

	i = 0;
	strlen = ft_strlen(*nbr_converted);
	temp = (char *) malloc(sizeof(char) * strlen + 2);
	while ((*nbr_converted)[i])
	{
		temp[i] = (*nbr_converted)[i];
		i++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	free(*nbr_converted);
	*nbr_converted = temp;
}

void	convert_nbr(long long nb, char *base, int nbase, char **nbr_converted)
{
	if (nb < 0)
	{
		add_char(nbr_converted, '-');
		nb = -nb;
		convert_nbr(nb, base, nbase, nbr_converted);
	}
	else if (nb > nbase - 1)
	{
		convert_nbr(nb / nbase, base, nbase, nbr_converted);
		convert_nbr(nb % nbase, base, nbase, nbr_converted);
	}
	else
		add_char(nbr_converted, base[nb]);
}
