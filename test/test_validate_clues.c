/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_clues.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:07:51 by chilim            #+#    #+#             */
/*   Updated: 2026/07/25 21:07:51 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rush01.h"
#include <stdio.h>

int		count_from_left(t_board *board, int row);
int		count_from_right(t_board *board, int row);
int		count_from_top(t_board *board, int col);
int		count_from_bottom(t_board *board, int col);
bool	are_all_clues_satisfied(t_board *board, t_clues *clues);

void	print_clues(t_clues *clues)
{
	int		i;
	int		group;
	int		*groups[4];
	char	value;

	group = 0;
	groups[0] = clues->top;
	groups[1] = clues->bottom;
	groups[2] = clues->left;
	groups[3] = clues->right;
	while (group < 4)
	{
		i = 0;
		while (i < SIZE)
		{
			value = groups[group][i] + '0';
			write(1, &value, 1);
			i++;
		}
		write(1, "\n", 1);
		group++;
	}
}

// ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
int	main(void)
{
	t_clues clues = {
	.top = {5, 3, 2, 1},
	.bottom = {1, 2, 2, 2},
	.left = {4, 3, 2, 1},
	.right = {1, 2, 2, 2}
	};

	t_board	board = {{
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	}};

	int clue_index = 0;
	print_clues(&clues);
	printf("\nFrom left: %d\n", count_from_left(&board, clue_index));
	printf("From right: %d\n", count_from_right(&board, clue_index));
	printf("From top: %d\n", count_from_top(&board, clue_index));
	printf("From bottom: %d\n", count_from_bottom(&board, clue_index));
	return (0);
}