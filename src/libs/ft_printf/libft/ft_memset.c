/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:45:32 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 16:53:02 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	d;
	size_t			index;
	char			*target;

	d = c;
	index = 0;
	target = b;
	while (index < len)
	{
		target[index] = d;
		index++;
	}
	return (b);
}
