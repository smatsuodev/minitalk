/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:33:42 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 20:23:15 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_percent_conv(t_output *output)
{
	output->buffer[0] = '%';
	output->buffer_size = 1;
	output->buffer_ptr = output->buffer;
}
