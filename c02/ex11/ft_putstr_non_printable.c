/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:01:31 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/30 15:14:19 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		if ((unsigned char)*str > 31 && (unsigned char)*str < 127)
		{
			c = (unsigned char) *str;
			write(1, &c, 1);
		}
		else
		{
			write(1, "\\", 1);
			write(1, &hex[(unsigned char)*str / 16], 1);
			write(1, &hex[(unsigned char)*str % 16], 1);
		}
		str++;
	}
}
