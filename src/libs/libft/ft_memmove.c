/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:27:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 17:02:15 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_rev(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*target;
	const char	*source;

	index = len - 1;
	target = dst;
	source = src;
	while (index >= 0)
	{
		target[index] = source[index];
		if (index == 0)
			break ;
		index--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*target;
	const char	*source;

	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dst > src)
		return (ft_memmove_rev(dst, src, len));
	index = 0;
	target = dst;
	source = src;
	while (index < len)
	{
		target[index] = source[index];
		index++;
	}
	return (dst);
}
