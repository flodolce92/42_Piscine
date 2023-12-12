/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:59:37 by flo-dolc          #+#    #+#             */
/*   Updated: 2023/12/09 04:49:30 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	int				nb;
	char			*literal;
	struct s_dict	*next;
}	t_dict;

int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_str_is_numeric(char *str);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);

#endif
