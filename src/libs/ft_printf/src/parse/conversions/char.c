/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:38:05 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:32:21 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_char_conv(t_output *output)
{
	output->conv_type = C_CHAR;
	output->buffer[0] = va_arg(*output->args, int);
	output->buffer_size = 1;
	output->buffer_ptr = output->buffer;
}
