/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:48:19 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/30 19:07:54 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hex_len(unsigned long input)
{
	int	counter;

	counter = 0;
	if (input == 0)
		counter++;
	while (input)
	{
		input /= 16;
		counter++;
	}
	return (counter);
}

void	ft_put_hex(unsigned long input, const char format)
{
	if (input >= 16)
	{
		ft_put_hex(input / 16, format);
		ft_put_hex(input % 16, format);
	}
	else
	{
		if (input <= 9)
			ft_printchar((input + '0'));
		else
		{
			if (format == 'x')
				ft_printchar((input - 10 + 'a'));
			else
				ft_printchar(input - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned long input, const char format)
{
	if (input == 0)
		return (ft_printchar('0'));
	ft_put_hex(input, format);
	return (ft_hex_len(input));
}
