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

#include "rush01.h"

int	count_from_left(t_board *board, int row);
int	count_from_right(t_board *board, int row);
int	count_from_top(t_board *board, int col);
int	count_from_bottom(t_board *board, int col);
bool	are_all_clues_satisfied(t_board *board, t_clues *clues);

