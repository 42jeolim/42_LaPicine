/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:06:49 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/23 14:03:07 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cal(int n, int m)
{
	char	a;
	char	b;

	if (n <= 9)
	{
		a = n + '0';
		write(1, "0", 1);
		write(1, &a, 1);
	}
	else if (n <= m)
	{
		a = n % 10 + '0';
		b = n / 10 + '0';
		write(1, &b, 1);
		write(1, &a, 1);
	}
}

void	comb(int f, int s)
{
	cal(f, 98);
	write(1, " ", 1);
	cal(s, 99);
	if (f != 98 || s != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			comb(a, b);
			b++;
		}
		a++;
	}
}
