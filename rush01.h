/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:11:28 by chilim            #+#    #+#             */
/*   Updated: 2026/07/23 19:55:29 by chilim           ###   ########.fr       */
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
}	t_grid;

// Parser
bool	is_valid_input(int argc, char **argv);

// Utils
int		error_return_one(void);

#endif