/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:53:35 by ahooghe           #+#    #+#             */
/*   Updated: 2023/03/30 18:41:53 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

//extra library functions
char	*ft_uitoa(unsigned int i);
//printing functions
int		ft_format(va_list input, const char format);
int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printint(int i);
int		ft_printhex(unsigned long i, const char format);
int		ft_printabsolute(unsigned int i);
int		ft_printptr(unsigned long long input);

#endif