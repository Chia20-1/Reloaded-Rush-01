/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:37 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 18:15:11 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_clues	clues;
	t_board	board;

	if (!is_valid_input(argc, argv))
		return (error_return_one());
	populate_clues(argv[1], &clues);
	init_board(&board);
	apply_deductions(clues, &board);
	// backtracking(&board);
	print_board(&board);
	return (0);
}
