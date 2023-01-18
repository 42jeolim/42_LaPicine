/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:18:23 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/04 10:13:33 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_printint(int size)
{
	char	c;

	if (size < 10)
	{
		c = size + '0';
		write(1, &c, 1);
		return ;
	}
	else
		ft_printint(size / 10);
	ft_printint(size % 10);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_printstr(par[i].str);
		write(1, "\n", 1);
		ft_printint(par[i].size);
		write(1, "\n", 1);
		ft_printstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
