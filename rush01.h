/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:11:28 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 17:34:04 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdbool.h>

# define SIZE 4

typedef struct s_clues
{
	int	top[SIZE];
	int	bottom[SIZE];
	int	left[SIZE];
	int	right[SIZE];
}	t_clues;

typedef struct s_board
{
	int	cells[SIZE][SIZE];
}	t_board;

// Input validation
bool        is_valid_input(int argc, char **argv);

// Init
t_clues     populate_clues(char *str, t_clues *clues);
void        init_board(t_board *board);

// Deduction
bool	    set_cell(t_board *board, int row, int col, int value);
bool	    apply_vertical_asc_four(t_board *board, int col);
bool	    apply_vertical_desc_four(t_board *board, int col);
bool	    apply_hoizontal_asc_four(t_board *board, int row);
bool	    apply_horizontal_desc_four(t_board *board, int row);
bool        apply_deductions(t_clues clues, t_board *board);

// Utils
int		    error_return_one(void);
void        print_board(int board[SIZE][SIZE]);

#endif