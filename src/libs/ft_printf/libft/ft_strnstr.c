/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:54:41 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/18 17:01:20 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_part_strnstr(const char *haystack, const char *needle,
		size_t len)
{
	unsigned char	h;
	unsigned char	n;
	size_t			index;
	int				is_eq;
	size_t			searched_len;

	searched_len = 0;
	while (*haystack != '\0' && searched_len + ft_strlen(needle) <= len)
	{
		index = 0;
		is_eq = 1;
		while (is_eq && searched_len + index < len && needle[index] != '\0')
		{
			h = (unsigned char)haystack[index];
			n = (unsigned char)needle[index];
			is_eq &= h == n;
			is_eq &= haystack[index] != '\0';
			index++;
		}
		if (is_eq)
			return ((char *)haystack);
		haystack++;
		searched_len++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (haystack == NULL)
		return (NULL);
	return (find_part_strnstr(haystack, needle, len));
}
