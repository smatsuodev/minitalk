/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:40:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 21:13:06 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_min_field_width(t_output *output)
{
	if (ft_isdigit(*output->fmt))
	{
		output->min_field_width = parse_int(output);
		if (output->flags & IS_ZEROFILL)
			output->padding = '0';
		else
			output->padding = ' ';
	}
}
