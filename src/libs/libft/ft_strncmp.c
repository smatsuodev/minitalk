/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:32:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/26 11:41:56 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				diff;
	size_t			index;
	unsigned char	c1;
	unsigned char	c2;

	index = 0;
	while (index < n)
	{
		c1 = s1[index];
		c2 = s2[index];
		diff = c1 - c2;
		if (diff != 0)
			return (diff);
		if (c1 == '\0' || c2 == '\0')
			return (0);
		index++;
	}
	return (0);
}
