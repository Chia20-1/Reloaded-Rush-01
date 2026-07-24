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

t_clues	populate_clues(char *str, t_clues *clues)
{
	int	index;
	int	value;

	index = 0;
	value = 0;
	while (index < SIZE * 4)
	{
		value = str[index * 2] - '0';
		if (index <= SIZE)
			clues->top[index] = value;
		else if (index <= SIZE * 2)
			clues->bottom[index] = value;
		else if (index <= SIZE * 3)
			clues->left[index] = value;
		else if (index <= SIZE * 4)
			clues->right[index] = value;
		index++;
		str += 2;
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
