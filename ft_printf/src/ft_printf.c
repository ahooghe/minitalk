/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:47:31 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/30 19:07:52 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_format(va_list input, const char format)
{
	int	printlength;

	printlength = 0;
	if (format == 'c')
		printlength += ft_printchar(va_arg(input, int));
	else if (format == 's')
		printlength += ft_printstr(va_arg(input, char *));
	else if (format == 'p')
		printlength += ft_printptr(va_arg(input, unsigned long long));
	else if (format == 'd' || format == 'i')
		printlength += ft_printint(va_arg(input, int));
	else if (format == 'u')
		printlength += ft_printabsolute(va_arg(input, unsigned int));
	else if (format == 'x' || format == 'X')
		printlength += ft_printhex(va_arg(input, unsigned int), format);
	else
		printlength += ft_printchar('%');
	return (printlength);
}

int	ft_printf(const char *str, ...)
{
	va_list	input;
	int		i;
	int		printlength;

	printlength = 0;
	i = 0;
	va_start(input, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printlength += ft_format(input, str[i]);
		}
		else
			printlength += ft_printchar(str[i]);
		i++;
	}
	va_end(input);
	return (printlength);
}
