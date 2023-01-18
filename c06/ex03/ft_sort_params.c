/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:20:52 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/01 22:14:49 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}	
	write(1, "\n", 1);
}

int	cmp_two(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx] && s1[idx] == s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = ac - 1;
	while (i >= 1)
	{
		j = 2;
		while (j <= i)
		{
			if (cmp_two(av[j - 1], av[j]) > 0)
			{
				tmp = av[j];
				av[j] = av[j - 1];
				av[j - 1] = tmp;
			}
			j++;
		}
		i--;
	}
	i = 0;
	while (i++ < ac - 1)
		ft_print(av[i]);
	return (0);
}
