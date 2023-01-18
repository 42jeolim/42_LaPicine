/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyoo <jungyoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:41:19 by jungyoo           #+#    #+#             */
/*   Updated: 2022/05/22 16:43:41 by jungyoo          ###   ########.fr       */
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
				ft_putchar('A');
			else if ((a == y && b == 1) || (b == x && a == 1))
				ft_putchar('C');
			else if ((a == 1 && b == 1))
				ft_putchar('A');
			else if (a != y && a != 1 && b != 1 && b != x)
				ft_putchar(' ');
			else
				ft_putchar('B');
			b--;
		}
		ft_putchar('\n');
		a--;
	}
}
