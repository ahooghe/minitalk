/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:58 by ahooghe           #+#    #+#             */
/*   Updated: 2023/01/19 19:07:08 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(little);
	if (!ft_strlen(little))
		return (big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		c = 0;
		while (big[i + c] != '\0' && little[c] != '\0' \
		&& big[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (big + i);
		i++;
	}
	return (0);
}
