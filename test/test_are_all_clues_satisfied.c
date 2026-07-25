/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_are_all_clues_satisfied.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:30:31 by chilim            #+#    #+#             */
/*   Updated: 2026/07/25 21:30:31 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rush01.h"
#include <stdio.h>

int		count_from_left(t_board *board, int row);
int		count_from_right(t_board *board, int row);
int		count_from_top(t_board *board, int col);
int		count_from_bottom(t_board *board, int col);
bool	are_all_clues_satisfied(t_board *board, t_clues *clues);

int	main(void)
{
	t_clues	clues = {
		{2, 3, 2, 1},
		{2, 1, 2, 3},
		{4, 1, 2, 2},
		{1, 4, 2, 2}
	};

	t_board	board = {{
		{1, 2, 3, 4},
		{4, 3, 2, 1},
		{2, 1, 4, 3},
		{3, 4, 1, 2}
	}};

	// clues.top[0] = 5;
	if (are_all_clues_satisfied(&board, &clues))
		printf("All clues are satisfied\n");
	else
		printf("Clues are not satisfied\n");
	return (0);
}