/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:48:16 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/06 21:19:01 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_length(char **strings, int size, char *sep)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_len(strings[index]);
		final_length += ft_len(sep);
		index++;
	}
	final_length -= ft_len(sep);
	return (final_length);
}

char	*word(int size, char **strs, char *sep, int length)
{
	int		idx;
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	i = -1;
	idx = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			res[idx++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			res[idx++] = sep[j++];
	}
	res[idx] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		length;

	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char));
		if (!arr)
			return (0);
		*arr = '\0';
		return (arr);
	}
	length = ft_length(strs, size, sep);
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (!arr)
		return (0);
	arr = word(size, strs, sep, length);
	return (arr);
}
