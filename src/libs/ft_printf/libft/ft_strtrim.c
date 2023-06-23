/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:05:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/17 23:09:28 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr((char *)set, s1[start]) != NULL)
		start++;
	while (ft_strrchr((char *)set, s1[end - 1]) != NULL)
		end--;
	return (ft_substr(s1, start, end - start));
}
