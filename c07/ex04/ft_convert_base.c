/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:04:53 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/09 09:47:36 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid(char *str);
int	is_space(char c);
int	ft_len3(char *str);
int	base_cal(char c, char *base);
int	get_digit(long long nb, int size);

int	check_in(char *base, char c)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

long long	atoi_base(char *str, char *base)
{
	int			len;
	long long	res;
	int			minus;

	minus = 1;
	res = 0;
	len = ft_len3(base);
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str && check_in(base, *str))
	{
		res = res * len + base_cal(*str, base);
		str++;
	}
	return (minus * res);
}

char	*base_num(int nv, long long nb, int size, char *base)
{
	char	*res;

	if (nb == 0)
	{
		res = (char *)malloc(sizeof(char) * nv + 1);
		res[0] = base[0];
		res[1] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * nv + 1);
	res[0] = '-';
	res[nv] = '\0';
	nb = -nb;
	while (nb > 0)
	{
		res[nv - 1] = base[nb % size];
		nb = nb / size;
		nv--;
	}
	return (res);
}

char	*itoa_base(long long nb, char *base)
{
	int			len;
	int			nv;
	char		*res;

	len = ft_len3(base);
	nv = get_digit((long long)nb, len);
	if (nb <= 0)
	{
		res = base_num(nv, (long long)nb, len, base);
		return (res);
	}
	res = (char *)malloc(sizeof(char) * nv);
	res[nv - 1] = '\0';
	while (nb > 0)
	{
		res[nv - 2] = base[nb % len];
		nb = nb / len;
		nv--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	nb;

	if (is_valid(base_from) || is_valid(base_to))
		return (0);
	nb = atoi_base(nbr, base_from);
	return (itoa_base(nb, base_to));
}
