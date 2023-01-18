/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:00:27 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/28 13:00:43 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_c;

	dest_c = ft_strlen(dest);
	if (dest_c >= size)
		return (ft_strlen(src) + size);
	while (dest_c + 1 < size && *src)
	{
		dest[dest_c] = *src;
		dest_c++;
		src++;
	}
	dest[dest_c] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
