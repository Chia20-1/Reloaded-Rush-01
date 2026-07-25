/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clue_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:29 by chilim            #+#    #+#             */
/*   Updated: 2026/07/25 21:09:54 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_from_left(t_board *board, int row)
{
	int	col;
	int	highest;
	int	visible;

	col = 0;
	highest = 0;
	visible = 0;
	while (col < SIZE)
	{
		if (board->cells[row][col] > highest)
		{
			highest = board->cells[row][col];
			visible++;
		}
		col++;
	}
	return (visible);
}

static int	count_from_right(t_board *board, int row)
{
	int	col;
	int	highest;
	int	visible;

	col = SIZE - 1;
	highest = 0;
	visible = 0;
	while (col >= 0)
	{
		if (board->cells[row][col] > highest)
		{
			highest = board->cells[row][col];
			visible++;
		}
		col--;
	}
	return (visible);
}

static int	count_from_top(t_board *board, int col)
{
	int	row;
	int	highest;
	int	visible;

	row = 0;
	highest = 0;
	visible = 0;
	while (row < SIZE)
	{
		if (board->cells[row][col] > highest)
		{
			highest = board->cells[row][col];
			visible++;
		}
		row++;
	}
	return (visible);
}

static int	count_from_bottom(t_board *board, int col)
{
	int	row;
	int	highest;
	int	visible;

	row = SIZE - 1;
	highest = 0;
	visible = 0;
	while (row >= 0)
	{
		if (board->cells[row][col] > highest)
		{
			highest = board->cells[row][col];
			visible++;
		}
		row--;
	}
	return (visible);
}

bool	are_all_clues_satisfied(t_board *board, t_clues *clues)
{
	int	index;

	index = 0;
	while (index < SIZE)
	{
		if (count_from_top(board, index) != clues->top[index])
			return (false);
		if (count_from_bottom(board, index) != clues->bottom[index])
			return (false);
		if (count_from_left(board, index) != clues->left[index])
			return (false);
		if (count_from_right(board, index) != clues->right[index])
			return (false);
		index++;
	}
	return (true);
}
