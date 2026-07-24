/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chilim <chilim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:24:41 by xinchong          #+#    #+#             */
/*   Updated: 2026/07/24 14:28:34 by chilim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
static void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
*/

static void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	error_return_one(void)
{
	ft_putstr("Error");
	return (1);
}

void	print_board(int board[SIZE][SIZE])
{
	int		row;
	int		column;
	char	c;

	row = 0;
	while (row < SIZE)
	{
		column = 0;
		while (column < SIZE)
		{
			c = board[row][column] + '0';
			ft_putchar(c);
			if (column < 3)
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
