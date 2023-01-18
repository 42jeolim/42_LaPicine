/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:54:36 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/23 13:33:51 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int array[], int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = array[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (array[0] != 10 - n)
		write(1, ", ", 2);
}

void	recursive(int array[], int n, int i)
{
	if (i == 0)
		array[i] = 0;
	else
		array[i] = array[i - 1] + 1;
	while (array[i] < 11 - n + i)
	{
		if (i == n - 1)
			ft_print(array, n);
		else
			recursive(array, n, i + 1);
		array[i] = array[i] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	recursive(array, n, 0);
}
