/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:05:26 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/26 13:02:31 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_addr(unsigned long long addr, unsigned int idx, char *hex)
{
	if (addr != 0)
	{
		ft_addr(addr / 16, idx + 1, hex);
		ft_putchar(hex[addr % 16]);
	}
	else
	{
		while (idx < 16)
		{
			ft_putchar('0');
			idx++;
		}
	}
}

void	print_hex(unsigned char *addr, int len, char *hex, char *str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (32 <= addr[i] && addr[i] <= 126)
			str[i] = addr[i];
		else
			str[i] = '.';
		ft_putchar(hex[addr[i] / 16]);
		ft_putchar(hex[addr[i] % 16]);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		write(1, "  ", 2);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*hex;
	char	str[16];
	int		tmp;
	char	i;

	hex = "0123456789abcdef";
	i = 0;
	while (size > 0)
	{
		if (size > 16)
			tmp = 16;
		else
			tmp = size;
		ft_addr((unsigned long long)addr + i, 0, hex);
		ft_putchar(':');
		print_hex((unsigned char *)addr + i, tmp, hex, str);
		ft_putchar(' ');
		write(1, str, tmp);
		ft_putchar('\n');
		i += 16;
		size -= tmp;
	}
	return (0);
}
