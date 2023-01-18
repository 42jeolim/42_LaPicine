/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:01:12 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/01 09:45:09 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	not_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (f_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base_cal(char *base, char c)
{
	int	i;

	i = 0;
	while (i < f_strlen(base))
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	i;
	int	minus;

	result = 0;
	minus = 1;
	i = 0;
	if (not_valid(base))
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= (-1);
		i++;
	}
	while (base_cal(base, str[i]) != -1)
	{
		result = base_cal(base, str[i]) + result * f_strlen(base);
		i++;
	}
	return (result * minus);
}
