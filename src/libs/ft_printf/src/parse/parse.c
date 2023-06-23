/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:13:18 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:28:21 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse(t_output *output)
{
	while (*output->fmt != '\0')
	{
		reset_buffer(output);
		if (consume(output, '%'))
		{
			parse_flags(output);
			parse_min_field_width(output);
			parse_precision(output);
			parse_conversion(output);
			if (output->is_err)
				return ;
			print(output);
			continue ;
		}
		put_char(output, *output->fmt);
		output->fmt++;
	}
}
