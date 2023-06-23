/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:42:41 by smatsuo           #+#    #+#             */
/*   Updated: 2023/05/22 18:42:58 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	init_dst_len;
	size_t	init_src_len;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (dstsize + ft_strlen(src));
	init_dst_len = ft_strlen(dst);
	init_src_len = ft_strlen(src);
	if (dstsize <= init_dst_len)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src != NULL && src[i] != '\0' && i + init_dst_len < dstsize - 1)
	{
		dst[i + init_dst_len] = src[i];
		i++;
	}
	if (i + init_dst_len < dstsize)
		dst[i + init_dst_len] = '\0';
	return (init_dst_len + init_src_len);
}
