/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:47:23 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/06 12:00:23 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && is_charset(str[i], charset) == 0)
		i++;
	return (i);
}

int	ft_all_word(char *str, char *charset)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset) == 1)
			str++;
		i = ft_strlen(str, charset);
		str += i;
		if (i)
			j++;
	}
	return (j);
}

char	*ft_strcpy(char *src, int j)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (j + 1));
	if (!res)
		return (0);
	while (i < j && src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;
	int		i;
	int		j;

	size = ft_all_word(str, charset);
	arr = (char **) malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		while (is_charset(*str, charset))
			str++;
		j = ft_strlen(str, charset);
		arr[i] = ft_strcpy(str, j);
		str += j;
		i++;
	}
	arr[size] = 0;
	return (arr);
}
