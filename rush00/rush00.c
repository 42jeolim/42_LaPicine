/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyoo <jungyoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:28:21 by jungyoo           #+#    #+#             */
/*   Updated: 2022/05/22 15:40:32 by jungyoo          ###   ########.fr       */
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
			if ((a == y || a == 1) && (b == x || b == 1))
				ft_putchar('o');
			else if ((a == y || a == 1) && (b != x && b != 1))
				ft_putchar('-');
			else if ((a != y && a != 1) && (b == x || b == 1))
				ft_putchar('|');
			else
				ft_putchar(' ');
			b -= 1;
		}
		ft_putchar('\n');
		a -= 1;
	}
}
