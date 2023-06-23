/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:57:21 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:31:28 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	put_char(t_output *output, char c)
{
	ssize_t	res;

	res = write(1, &c, 1);
	if (res == -1)
	{
		output->is_err = 1;
		return ;
	}
	output->written_size++;
}

void	put_char_rep(t_output *output, char c, int times)
{
	while (times-- > 0)
		put_char(output, c);
}

void	put_str(t_output *output, char *s)
{
	put_strn(output, s, ft_strlen(s));
}

void	put_strn(t_output *output, char *s, size_t len)
{
	ssize_t	res;

	res = write(1, s, len);
	if (res == -1)
	{
		output->is_err = 1;
		return ;
	}
	output->written_size += res;
}
