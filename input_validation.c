/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:45:29 by chilim            #+#    #+#             */
/*   Updated: 2026/07/24 18:09:18 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static bool	is_valid_number(char c)
{
	if (c >= '1' && c <= '4')
		return (true);
	else
		return (false);
}

static bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	else
		return (false);
}

// Checking alternate number and space pattern
static bool	is_valid_string(char *str)
{
	bool	expect_number;

	expect_number = true;
	while (*str)
	{
		if (expect_number)
		{
			if (!is_valid_number(*str))
				return (false);
			expect_number = false;
		}
		else if (!expect_number)
		{
			if (!is_space(*str))
				return (false);
			expect_number = true;
		}
		str++;
	}
	if (!expect_number)
		return (true);
	else
		return (false);
}

// Checking whether there are 16 numbers
static bool	has_valid_count(char *str)
{
	int		counter;

	counter = 0;
	while (*str)
	{
		if (is_valid_number(*str))
			counter++;
		str++;
	}
	if (counter != 16)
		return (false);
	else
		return (true);
}

bool	is_valid_input(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	if (!is_valid_string(argv[1]) || !has_valid_count(argv[1]))
		return (false);
	return (true);
}
