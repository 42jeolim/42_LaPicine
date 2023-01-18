/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyoo <jungyoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:44:55 by jungyoo           #+#    #+#             */
/*   Updated: 2022/05/22 16:10:24 by jungyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	a;
	int	b;

	a = y;
	while (a > 0 && x > 0)
	{
		b = x;
		while (b > 0)
		{
			if ((a == y && b == x))
				ft_putchar('/');
			else if ((a == y && b == 1) || (b == x && a == 1))
				ft_putchar('\\');
			else if ((a == 1 && b == 1))
				ft_putchar('/');
			else if (a != y && a != 1 && b != 1 && b != x)
				ft_putchar(' ');
			else
				ft_putchar('*');
			b--;
		}
		ft_putchar('\n');
		a--;
	}
}
