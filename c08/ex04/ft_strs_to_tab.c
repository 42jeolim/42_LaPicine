/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:14:11 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/04 10:26:34 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(char *str, int size)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*point;
	int			i;
	int			len;

	i = 0;
	point = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!point)
		return (0);
	while (i < ac)
	{
		len = ft_len(av[i]);
		point[i].size = len;
		point[i].str = av[i];
		point[i].copy = ft_strdup(av[i], len);
		i++;
	}
	point[i].str = 0;
	return (point);
}
