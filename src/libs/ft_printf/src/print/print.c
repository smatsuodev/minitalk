/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:24:15 by smatsuo           #+#    #+#             */
/*   Updated: 2023/06/07 23:31:07 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	print(t_output *output)
{
	if (output->padding == ' ' && !(output->flags & IS_ALIGNLEFT))
		print_min_field_width(output);
	print_sign(output);
	if (output->padding == '0' && !(output->flags & IS_ALIGNLEFT))
		print_min_field_width(output);
	print_content(output);
	if (output->padding == ' ' && (output->flags & IS_ALIGNLEFT))
		print_min_field_width(output);
}

void	print_min_field_width(t_output *output)
{
	if (output->min_field_width <= precise_content_size(output))
		return ;
	put_char_rep(output, output->padding,
		output->min_field_width - (int)precise_content_size(output));
}

void	print_sign(t_output *output)
{
	if (output->sign == '\0')
		return ;
	put_char(output, output->sign);
}

void	print_content(t_output *output)
{
	if (output->precision != -1 && output->conv_type == C_STR)
		output->buffer_size = precise_content_size(output);
	if (output->precision != -1 && output->conv_type != C_STR)
	{
		if (output->precision == 0 && output->conv_type != C_CHAR
			&& output->buffer_ptr[0] == '0')
			return ;
		if (!(output->flags & IS_ALT_FMT) || output->buffer_ptr[0] != '0')
			put_str(output, output->prefix);
		if (precise_content_size(output) > content_size(output))
			put_char_rep(output, '0',
				precise_content_size(output) - content_size(output));
	}
	else if (!(output->flags & IS_ALT_FMT) || output->buffer_ptr[0] != '0')
		put_str(output, output->prefix);
	put_strn(output, output->buffer_ptr, output->buffer_size);
}
