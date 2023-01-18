/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeolim <jeolim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:15:37 by jeolim            #+#    #+#             */
/*   Updated: 2022/06/02 11:23:16 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * (-1));
	return (nb);
}

void	printqueens(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	promising(int idx, int *board)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (board[idx] == board[i] || idx - i == ft_abs(board[idx] - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	nqueen(int idx, int *board, int *count)
{
	int	i;

	if (idx == 10)
	{
		(*count)++;
		printqueens(board);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		board[idx] = i;
		if (promising(idx, board))
			nqueen(idx + 1, board, count);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	nqueen(0, board, &count);
	return (count);
}
