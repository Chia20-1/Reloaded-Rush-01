/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:25 by chilim            #+#    #+#             */
/*   Updated: 2026/07/25 22:15:54 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// Uses check-duplicate rule
static bool	is_valid_placement(t_board *board, int row, int col, int value)
{
	int	index;

	index = 0;
	while (index < SIZE)
	{
		if (index != col && board->cells[row][index] == value)
			return (false);
		if (index != row && board->cells[index][col] == value)
			return (false);
		index++;
	}
	return (true);
}

static bool	try_values(t_board *board, t_clues *clues, int position)
{
	int	row;
	int	col;
	int	value;

	row = position / SIZE;
	col = position % SIZE;
	value = 1;
	while (value <= SIZE)
	{
		if (is_valid_placement(board, row, col, value))
		{
			board->cells[row][col] = value;
			if (backtrack(board, clues, position + 1))
				return (true);
			board->cells[row][col] = 0;
		}
		value++;
	}
	return (false);
}

bool	backtrack(t_board *board, t_clues *clues, int position)
{
	int	row;
	int	col;
	int	current_cell;

	if (position == SIZE * SIZE)
		return (are_all_clues_satisfied(board, clues));
	row = position / SIZE;
	col = position % SIZE;
	current_cell = board->cells[row][col];
	if (current_cell == 0)
		return (try_values(board, clues, position));
	if (!is_valid_placement(board, row, col, current_cell))
		return (false);
	return (backtrack(board, clues, position + 1));
}
