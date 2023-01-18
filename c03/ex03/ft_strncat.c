/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:37:24 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/26 13:45:59 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_c;

	dest_c = 0;
	while (dest[dest_c])
	{
		dest_c++;
	}
	while (*src && nb > 0)
	{
		dest[dest_c] = *src;
		src++;
		dest_c++;
		nb--;
	}
	dest[dest_c] = '\0';
	return (dest);
}
