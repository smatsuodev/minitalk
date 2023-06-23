/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:23:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 16:50:33 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*target;
	const char	*source;

	index = 0;
	target = dst;
	source = src;
	if (!target && !source)
		return (NULL);
	while (index < n)
	{
		target[index] = source[index];
		index++;
	}
	return (dst);
}
