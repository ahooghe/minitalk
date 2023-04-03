/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:26:08 by ahooghe           #+#    #+#             */
/*   Updated: 2023/01/16 12:48:27 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	destlen;

	j = 0;
	srclen = ft_strlen(src);
	if (n == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	i = destlen;
	if (!src || !dest)
		return (0);
	if (n < destlen)
		return (srclen + n);
	else
	{
		while (src[j] && (destlen + j) < (n))
			dest[i++] = src[j++];
		if ((destlen + j) == n && destlen < n)
			dest[--i] = '\0';
		else
			dest[i] = '\0';
		return (srclen + destlen);
	}
}
