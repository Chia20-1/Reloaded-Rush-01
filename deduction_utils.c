/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deduction_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:49:57 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 17:28:13 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

bool	set_cell(t_board *board, int row, int col, int value)
{
	int	current;

	current = board->cells[row][col];
	if (current != 0 && current != value)
		return (false);
	board->cells[row][col] = value;
	return (true);
}

bool	apply_vertical_asc_four(t_board *board, int col)
{
	int	row;

	row = 0;
	while (row < SIZE)
	{
		if (!set_cell(board, row, col, row + 1))
			return (false);
		row++;
	}
	return (true);
}

bool	apply_vertical_desc_four(t_board *board, int col)
{
	int	row;

	row = 0;
	while (row < SIZE)
	{
		if (!set_cell(board, SIZE - row - 1, col, row + 1))
			return (false);
		row++;
	}
	return (true);
}

bool	apply_hoizontal_asc_four(t_board *board, int row)
{
	int	col;

	col = 0;
	while (row < SIZE)
	{
		if (!set_cell(board, row, col, col + 1))
			return (false);
		row++;
	}
	return (true);
}

bool	apply_horizontal_desc_four(t_board *board, int row)
{
	int	col;

	col = 0;
	while (row < SIZE)
	{
		if (!set_cell(board, row, SIZE - col - 1, col + 1))
			return (false);
		row++;
	}
	return (true);
}
