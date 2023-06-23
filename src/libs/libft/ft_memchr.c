/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:29:47 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/22 06:51:12 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	target;
	char	*str;
	size_t	index;

	target = c;
	str = (char *)s;
	index = 0;
	while (index < n)
	{
		if (*str == target)
			return (str);
		++str;
		++index;
	}
	return (NULL);
}
