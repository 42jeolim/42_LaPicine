/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:40 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/24 16:37:23 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = size - 1;
	while (i >= 0)
	{
		j = 1;
		while (j <= i)
		{
			if (tab[j - 1] > tab[j])
				swap(&tab[j - 1], &tab[j]);
			j++;
		}
		i--;
	}
}
