/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:34:38 by jeolim            #+#    #+#             */
/*   Updated: 2022/05/24 16:36:43 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rem;

	if (*b != 0)
	{
		div = (*a) / (*b);
		rem = (*a) % (*b);
		*a = div;
		*b = rem;
	}
}
