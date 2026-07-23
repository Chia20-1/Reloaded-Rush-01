/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:45:29 by chilim            #+#    #+#             */
/*   Updated: 2026/07/23 19:54:34 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush01.h>

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
	if (argv != 2)
		return (false);
	if (!is_valid_string && !has_valid_count)
		return (false);
	return (true);
}
