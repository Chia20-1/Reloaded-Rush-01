/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:40 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 18:17:30 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	populate_clues(char *str, t_clues *clues)
{
	int	clue_index;
	int	value;

	clue_index = 0;
	while (clue_index < SIZE * 4)
	{
		value = str[clue_index * 2] - '0';
		if (clue_index < SIZE)
			clues->top[clue_index] = value;
		else if (clue_index < SIZE * 2)
			clues->bottom[clue_index - SIZE] = value;
		else if (clue_index < SIZE * 3)
			clues->left[clue_index - (SIZE * 2)] = value;
		else if (clue_index < SIZE * 4)
			clues->right[clue_index - (SIZE * 3)] = value;
		clue_index++;
	}
}

void	init_board(t_board *board)
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			board->cells[row][col] = 0;
			col++;
		}
		row++;
	}
}
