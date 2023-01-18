/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:46:47 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/29 18:05:06 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	x;

	idx = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[idx])
	{
		x = 0;
		while (str[idx + x] == to_find[x] && str[idx + x])
		{
			if (to_find[x + 1] == '\0')
				return (&str[idx]);
			x++;
		}
		idx++;
	}
	return (0);
}
