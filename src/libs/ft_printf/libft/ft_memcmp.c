/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:49:45 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 16:47:54 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	index;
	int		diff;

	str1 = (char *)s1;
	str2 = (char *)s2;
	index = 0;
	while (index < n)
	{
		diff = (unsigned char)str1[index] - (unsigned char)str2[index];
		if (diff != 0)
			return (diff);
		index++;
	}
	return (0);
}
