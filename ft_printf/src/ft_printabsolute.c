/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printabsolute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:29:30 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/30 19:07:26 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	amount_nbrs(unsigned int input)
{
	int	i;

	i = 0;
	while (input)
	{
		input = input / 10;
		i++;
	}
	return (i);
}

int	ft_printabsolute(unsigned int input)
{
	if (input == 0)
	{
		ft_printchar('0');
		return (amount_nbrs(input) + 1);
	}
	if (input >= 10)
	{
		ft_printabsolute(input / 10);
		ft_printchar(input % 10 + '0');
	}
	else
	{
		ft_printchar(input + '0');
	}
	return (amount_nbrs(input));
}
