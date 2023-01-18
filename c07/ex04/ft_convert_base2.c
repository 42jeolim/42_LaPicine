/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:02:36 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/08 20:30:05 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len3(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' )
		return (1);
	return (0);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_len3(str) < 2)
		return (1);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || is_space(str[i]))
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base_cal(char c, char *base)
{
	int	idx;

	idx = 0;
	while (*base)
	{
		if (*base == c)
			return (idx);
		idx++;
		base++;
	}
	return (0);
}

int	get_digit(long long nb, int size)
{
	int	out;

	out = 1;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		out++;
		nb = nb / size;
	}
	return (out);
}
