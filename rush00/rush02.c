/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungyoo <jungyoo@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:19:35 by jungyoo           #+#    #+#             */
/*   Updated: 2022/05/22 16:30:19 by jungyoo          ###   ########.fr       */
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
			if ((a == y && b == x) || (a == y && b == 1))
				ft_putchar('A');
			else if (a == 1 && (b == x || b == 1))
				ft_putchar('C');
			else if ((a == 1 || a == y) || (b == 1 || b == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
			b -= 1;
		}
		ft_putchar('\n');
		a -= 1;
	}
}
