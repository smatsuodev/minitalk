/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:10:06 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/17 23:44:00 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;
	size_t			cpy_len;

	cpy_len = ft_min(ft_strlen(s) - start, len);
	if (ft_strlen(s) < 1 + start)
		cpy_len = 0;
	cpy = (char *)malloc(cpy_len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < cpy_len && s[i + start] != '\0')
	{
		cpy[i] = s[i + start];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
