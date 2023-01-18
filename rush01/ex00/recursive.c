/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:32:45 by jerhee            #+#    #+#             */
/*   Updated: 2022/05/29 15:34:38 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int	recursive(int board[8][8], int *num, int point, int size)
{
	int	res;

	if (point == size * size)
		return (1);
	res = 1;
	while (res <= size)
	{	
		if (basic_check(board, point, res, size))
		{
			board[point / size][point % size] = res;
			if (board_check(board, num, point, size))
			{
				if (recursive(board, num, point + 1, size))
					return (1);
			}
		}
		res++;
	}
	return (0);
}

int	basic_check(int board[8][8], int point, int res, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < point / size)
	{
		if (board[x][point % size] == res)
			return (0);
		x++;
	}
	y = 0;
	while (y < point % size)
	{
		if (board[point / size][y] == res)
			return (0);
		y++;
	}
	return (1);
}

void	print_board(int board[8][8], int size)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			c = board[x][y] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

void	init_board(int board[8][8], int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			board[x][y] = 0;
			y++;
		}
		x++;
	}
}
