/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:11:28 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 18:08:27 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rush01.h"
#include <stdio.h>

// Test print clues
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

// Test check duplicate
int	main(void)
{
	t_board	board = {
		{
			{0, 2, 3, 4},
			{0, 3, 4, 1},
			{0, 4, 1, 2},
			{0, 1, 2, 3},
		}
	};
	if (check_duplicate(&board, 0, 0, 2))
		printf("%s\n", "Valid");
	else
		printf("%s\n", "Invalid");
	print_board(&board);
	return (0);
}
