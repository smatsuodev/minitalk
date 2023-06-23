/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:40:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:32:49 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	parse_str_conv(t_output *output)
{
	output->conv_type = C_STR;
	output->buffer_ptr = va_arg(*output->args, char *);
	if (output->buffer_ptr == NULL)
		output->buffer_ptr = "(null)";
	output->buffer_size = ft_strlen(output->buffer_ptr);
}
