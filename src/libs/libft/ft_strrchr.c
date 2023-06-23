/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:24:07 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 17:02:02 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		index;
	char	target;

	index = ft_strlen(s);
	target = c;
	while (index >= 0)
	{
		if (s[index] == target)
			return (s + index);
		--index;
	}
	return (NULL);
}
