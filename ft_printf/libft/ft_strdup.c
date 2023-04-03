/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:10:22 by ahooghe           #+#    #+#             */
/*   Updated: 2023/01/11 15:14:33 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(str1);
	new = malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
