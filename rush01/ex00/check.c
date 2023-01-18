/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:26:20 by jerhee            #+#    #+#             */
/*   Updated: 2022/05/29 16:44:04 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int board[8][8], int *num, int point, int size)
{
	int	x;
	int	max;
	int	count;

	x = 0;
	max = 0;
	count = 0;
	if (point / size == size - 1)
	{
		while (x < size)
		{
			if (board[x][point % size] > max)
			{
				max = board[x][point % size];
				count++;
			}
			x++;
		}
		if (num[point % size] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int board[8][8], int *num, int point, int size)
{
	int	x;
	int	max;
	int	count;

	x = size - 1;
	max = 0;
	count = 0;
	if (point / size == size - 1)
	{
		while (x >= 0)
		{
			if (board[x][point % size] > max)
			{
				max = board[x][point % size];
				count++;
			}
			x--;
		}
		if (num[size + point % size] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int board[8][8], int *num, int point, int size)
{
	int	y;
	int	max;
	int	count;

	y = 0;
	max = 0;
	count = 0;
	if (point % size == size - 1)
	{
		while (y < size)
		{
			if (board[point / size][y] > max)
			{
				max = board[point / size][y];
				count++;
			}
			y++;
		}
		if (num[size * 2 + point / size] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int board[8][8], int *num, int point, int size)
{
	int	y;
	int	max;
	int	count;

	y = size - 1;
	max = 0;
	count = 0;
	if (point % size == size - 1)
	{
		while (y >= 0)
		{
			if (board[point / size][y] > max)
			{
				max = board[point / size][y];
				count++;
			}
			y--;
		}
		if (num[size * 3 + point / size] != count)
			return (0);
	}
	return (1);
}

int	board_check(int board[8][8], int *num, int point, int size)
{
	if (!(check_col_up(board, num, point, size)))
		return (0);
	if (!(check_col_down(board, num, point, size)))
		return (0);
	if (!(check_row_left(board, num, point, size)))
		return (0);
	if (!(check_row_right(board, num, point, size)))
		return (0);
	return (1);
}
