/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:23:55 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/22 22:03:15 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Allocate an array of char* setting NULL in the 0th position.
static int	get_arr_len(char const *s, char c)
{
	int	arr_len;
	int	i;

	arr_len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != 0)
			arr_len++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (arr_len);
}

char	*try_push_substr(char const *s, unsigned int start, size_t len,
		char ***arr)
{
	char	*substr;
	size_t	i;

	substr = ft_substr(s, start, len);
	i = 0;
	if (substr == NULL)
	{
		while (*arr[i] != NULL)
		{
			free(*arr[i]);
			i++;
		}
		return (NULL);
	}
	while ((*arr)[i] != NULL)
		i++;
	(*arr)[i] = substr;
	(*arr)[i + 1] = NULL;
	return (substr);
}

char	**split_by(char const *s, char c, char **arr)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != 0 && try_push_substr(s, start, i - start, &arr) == NULL)
			return (NULL);
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;

	arr_len = get_arr_len(s, c);
	arr = (char **)ft_calloc(arr_len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (split_by(s, c, arr));
}
