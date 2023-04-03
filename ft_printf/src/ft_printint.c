/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:26:05 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/30 19:07:57 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printint(int input)
{
	char	*num;
	int		len;

	if (input == 0)
		return (ft_printchar('0'));
	num = ft_itoa(input);
	if (!num)
		return (0);
	ft_printstr(num);
	len = ft_strlen(num);
	free(num);
	return (len);
}
