/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deduction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:42 by chilim            #+#    #+#             */
/*   Updated: 2026/07/26 14:14:52 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static bool	apply_vertical(t_clues clues, t_board *board, int index)
{
	if (clues.top[index] == 1 && !set_cell(board, 0, index, SIZE))
		return (false);
	if (clues.bottom[index] == 1 && !set_cell(board, SIZE - 1, index, SIZE))
		return (false);
	if (clues.top[index] == SIZE && !apply_vertical_asc(board, index))
		return (false);
	if (clues.bottom[index] == SIZE && !apply_vertical_desc(board, index))
		return (false);
	return (true);
}

static bool	apply_horizontal(t_clues clues, t_board *board, int index)
{
	if (clues.left[index] == 1 && !set_cell(board, index, 0, SIZE))
		return (false);
	if (clues.right[index] == 1 && !set_cell(board, index, SIZE - 1, SIZE))
		return (false);
	if (clues.left[index] == SIZE && !apply_horizontal_asc(board, index))
		return (false);
	if (clues.right[index] == SIZE && !apply_horizontal_desc(board, index))
		return (false);
	return (true);
}

bool	apply_deductions(t_clues clues, t_board *board)
{
	int	index;

	index = 0;
	while (index < SIZE)
	{
		if (!apply_vertical(clues, board, index))
			return (false);
		if (!apply_horizontal(clues, board, index))
			return (false);
		index++;
	}
	return (true);
}
