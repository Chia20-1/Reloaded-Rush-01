/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:25 by chilim            #+#    #+#             */
/*   Updated: 2026/07/25 20:31:18 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static bool	check_duplicate(t_board *board, int row, int col, int value)
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

bool	backtrack(t_board *board, t_clues *clues, int position)
{
	if (position == SIZE * SIZE)
		return (are_all_clues_satisfied(board, clues));

	row = position / SIZE;
	col =  position % SIZE;

	if (board->cells[row][col] != 0)
	{
		if (is_valid_placement(board, row, col, ))	
	}
}