/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:34:45 by jerhee            #+#    #+#             */
/*   Updated: 2022/05/29 17:17:38 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

int		check_argv(int argc, char **argv, int size);
int		*get_num(char *str, int *num);
int		get_num_size(char *str);
int		ft_strlen(char *str);

int		board_check(int board[8][8], int *num, int point, int size);
int		check_col_up(int board[8][8], int *num, int point, int size);
int		check_row_right(int board[8][8], int *num, int point, int size);
int		check_col_down(int board[8][8], int *num, int point, int size);
int		check_row_left(int board[8][8], int *num, int point, int size);

int		recursive(int board[8][8], int *num, int point, int size);
int		basic_check(int board[8][8], int point, int res, int size);
void	print_board(int board[8][8], int size);
void	init_board(int board[8][8], int size);

#endif
