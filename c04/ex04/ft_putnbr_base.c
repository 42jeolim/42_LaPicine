/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:30:35 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/31 19:11:30 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_len(str) < 2)
		return (1);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (is_valid(base))
		return ;
	base_len = ft_len(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(2147483648 / base_len, base);
		ft_putnbr_base(2147483648 % base_len, base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= (-1);
	}
	if (nbr < base_len)
	{
		write(1, &base[nbr], 1);
		return ;
	}
	ft_putnbr_base(nbr / base_len, base);
	ft_putnbr_base(nbr % base_len, base);
}
