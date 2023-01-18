/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:03:57 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/09 15:32:36 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map.c(int *tab, int length, int(*f)(int))
{
	int	i;
	int	result;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * length);
	i = 0;
	result = 0;
	while (i < length)
	{
		arr[i] = tab[i];
		i++;
	}
	return (arr);
}
