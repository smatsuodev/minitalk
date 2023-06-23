/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:52:42 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 22:19:33 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_precision(t_output *output)
{
	if (consume(output, '.'))
	{
		output->precision = parse_int(output);
		if (output->padding == '0')
			output->padding = ' ';
	}
}
