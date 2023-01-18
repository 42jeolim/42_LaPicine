/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:30:06 by jerhee            #+#    #+#             */
/*   Updated: 2022/05/29 18:55:10 by jeolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	int	board[8][8];
	int	*num;
	int	size;

	size = 0;
	if (argc == 2)
		size = get_num_size(argv[1]);
	if (!check_argv(argc, argv, size))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	num = (int *)malloc(sizeof(int) * (size * size));
	if (!num)
		return (0);
	get_num(argv[1], num);
	init_board(board, size);
	if (recursive(board, num, 0, size))
		print_board(board, size);
	else
		write(2, "Error\n", 6);
	free(num);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_num_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			size++;
		i++;
	}
	return (size / 4);
}

int	*get_num(char *str, int *num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (num);
}

int	check_argv(int argc, char **argv, int size)
{
	int	i;

	if (argc != 2)
		return (0);
	if ((ft_strlen(argv[1]) != (size * 8) - 1) || (ft_strlen(argv[1]) < 31))
		return (0);
	i = 1;
	while (argv[1][i])
	{
		if (argv[1][i] != ' ')
			return (0);
		i += 2;
	}
	return (1);
}
