/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 05:30:40 by hyunklee          #+#    #+#             */
/*   Updated: 2021/04/11 03:54:40 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

char g_board[10][10];
char g_sol[10];

int	check_point1(int row, int col);
void	recursive_queens(int depth);
int	ft_ten_queens_puzzle(void);
void	print_board(void);
int	check_point2(int row, int col);

int	check_point2(int row, int col)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= col)
	{
		if (g_board[row][col - j] == 1)
			return(0);
		j++;
	}
	i = 1;
	j = 1;
	while (row - i >= 0 && col + j <= 9)
	{
		if (g_board[row - i][col + j] == 1)
			return(0);
		i++;
		j++;
	}
	return (1);
}

int	check_point1(int row, int col)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (row - i >= 0 && col - j >= 0)
	{
		if (g_board[row - i][col - j] == 1)
			return (0);
		i++;
		j++;
	}
	i = 1;
	j = 1;
	while (i <= row)
	{
		if (g_board[row - i][col] == 1)
			return (0);
		i++;
	}
	return (1);
}
	
void	recursive_queens(int depth)
{
	int col;

	col = 0;
	if (depth == 10)
	{
		print_board();
		return;
	}
	while (col < 10 && depth < 10)
	{
		if (check_point1(depth, col)&& check_point2(depth, col))
		{
			g_board[depth][col] = 1;
			recursive_queens(depth + 1);
			g_board[depth][col] = 0;
		}
		col++;
	}
}

void	print_board(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 9)
	{
		while (j <= 9)
		{
			if (g_board[i][j] == 1)
				g_sol[i] = j + '0';
			j++;
		}
											
		j = 0;				
		i++;
	}
	i = 0;
	while (i <= 9)
	{
		write(1, &g_sol[i], 1);
		g_sol[i] = 0;
		i++;
	}
	write(1, "\n", 1);
}

int	ft_ten_queens_puzzle(void)
{
	recursive_queens(0);
	return (0);

}

int	main(void)
{

	ft_ten_queens_puzzle();
}

