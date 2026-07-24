/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:19:40 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 13:55:59 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

t_clues populate_clues(char *str, t_clues *clues)
{
	int index;
	int value;

	index = 0;
	value = 0;
	while (index < SIZE * 4)
	{
		value = str[index * 2] - '0';
		// Top 
		if (index <= SIZE)
			clues->top[index] = value;
		// Bottom
		else if ()
			clues->bottom[index] = value;
		// Left
		else if ()
			clues->left[index] = value;
		// Right
		else if ()
			clues->right[index] = value;
		index++;
	}
}
