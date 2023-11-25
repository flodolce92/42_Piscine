/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:54:50 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/09/26 20:57:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_uppercase(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	fl;

	i = 0;
	fl = 1;
	while (str[i] != '\0')
	{
		if (isalnum(str[i]) == 0)
			fl = 1;
		else if (fl == 1 && is_lowercase(str[i]))
		{
			str[i] = str[i] - 32;
			fl = 0;
		}
		else if (fl == 1 && is_uppercase(str[i]))
			fl = 0;
		else if (fl == 0 && is_uppercase(str[i]))
			str[i] = str[i] + 32;
		else if (fl == 1 && str[i] >= '0' && str[i] <= '9')
			fl = 0;
		i++;
	}
	return (str);
}
