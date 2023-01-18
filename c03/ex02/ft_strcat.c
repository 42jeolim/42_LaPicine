/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:29:31 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/26 13:36:57 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (dest[idx])
	{
		idx++;
	}
	while (*src)
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
