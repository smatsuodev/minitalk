/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:50:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/08 02:46:04 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	content_size(t_output *output)
{
	if (output->conv_type == C_STR)
		return (output->buffer_size);
	if (output->sign == '\0')
		return (output->buffer_size + ft_strlen(output->prefix));
	return (output->buffer_size + ft_strlen(output->prefix) + 1);
}

int	precise_content_size(t_output *output)
{
	if (output->conv_type == C_STR)
	{
		if (output->precision == -1)
			return (content_size(output));
		return (ft_min((int)content_size(output), output->precision));
	}
	if (output->precision == 0 && output->conv_type != C_CHAR
		&& output->buffer_ptr[0] == '0')
		return (0);
	if (output->precision == -1 || output->buffer_size > output->precision)
		return (content_size(output));
	if (output->sign == '\0')
		return (output->precision + ft_strlen(output->prefix));
	return (output->precision + ft_strlen(output->prefix) + 1);
}

void	init_output(t_output *output)
{
	output->is_err = 0;
	output->fmt = NULL;
	output->args = NULL;
	output->buffer_ptr = NULL;
	output->conv_type = 0;
	output->flags = 0;
	output->written_size = 0;
	output->buffer_size = 0;
	output->min_field_width = -1;
	output->precision = -1;
	output->padding = 0;
	output->sign = '\0';
	output->prefix = NULL;
}

void	reset_buffer(t_output *output)
{
	output->buffer_ptr = NULL;
	output->conv_type = 0;
	output->flags = 0;
	output->buffer_size = 0;
	output->min_field_width = -1;
	output->precision = -1;
	output->padding = 0;
	output->sign = '\0';
	output->prefix = NULL;
}
