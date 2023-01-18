/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:19:26 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/23 13:40:42 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{	
	char	tmp;

	tmp = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb <= 9)
	{
		tmp = nb + '0';
		write(1, &tmp, 1);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	tmp = nb % 10;
	ft_putnbr(tmp);
}
